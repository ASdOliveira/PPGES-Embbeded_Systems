#include <main.h>
#use delay(crystal=20000000)

#include "typedef.h"
#include "utils.h"
#include "joystick.h"

long int AD0,AD1;
bool setAD = false;
EDirections direction;

void main()
{
 setup_timer_1( T1_INTERNAL | T1_DIV_BY_1);
 setup_timer_2(T2_DIV_BY_16,250,16); //16*250*0,2u = 0,8ms para a base de tempo
  
  // enable_interrupts(global);        //habilita a interrup??o global
 //  enable_interrupts(int_timer2);    //habilita a interrup??o de timer2, vou manter a interrup??o de timer 2
                                     //mesmo com ele sendo utilizado para a base de tempo do PWM
   setup_ccp1(CCP_PWM);              //configura o CCP1 como PWM
   setup_ccp2(CCP_PWM); 
   setup_adc(ADC_CLOCK_DIV_32);   //configura conversor AD
   setup_adc_ports(AN0_AN1_AN3);          //escolhe apenas o pino A0 como entrada anal?gica
   

   while (true)            //loop de repeti??o do c?digo principal
   {
    setAD = !setAD; //com isso, é perdido apenas 50ms/ciclo. Ao invés dos 100ms, já que não precisa tanta rapidez assim..
    
    if(setAD == true)
    {
      set_adc_channel(0);      //escolhe canal 0 para a convers?o
      delay_ms(50);            //espera um tempo para a tens?o se estabilizar
      AD0 = read_adc();         //inicia a convers?o espera ela ser concluida e retorna o valor convertido
    }
    else
    {
      set_adc_channel(1);      //escolhe canal 0 para a convers?o
      delay_ms(50);            //espera um tempo para a tens?o se estabilizar
      AD1 = read_adc();         //inicia a convers?o espera ela ser concluida e retorna o valor convertido
    }
  
   direction = joystick(AD0,AD1);
   
   switch(direction)
   {
      case FRENTE: 
      set_pwm1_duty(800);
      set_pwm2_duty(800);
      output_b(0x05);      
      break;
      
      case TRAS:
      set_pwm1_duty(800);
      set_pwm2_duty(800);
      output_b(0x0A);      
      break;
      //Curvas devem ser feitas com diferenças na velocidade entre as rodas
      case DIREITA:
      set_pwm1_duty(800);
      set_pwm2_duty(200);
      //output_b(0x05);      
      output_b(0x06);
      break;
      
      case ESQUERDA:
      set_pwm1_duty(200);
      set_pwm2_duty(800);
      //output_b(0x05);
      output_b(0x09);
      break;
      
      case PARAR:
      set_pwm1_duty(0);
      set_pwm2_duty(0);
      output_b(0x0F);
      break;
   }
   
   }   // fim do while

}
