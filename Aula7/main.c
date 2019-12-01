#include <main.h>
#use delay(crystal=20000000)
#use rs232 (baud = 9600, bits = 8, parity = N, uart1, errors)

#include "typedef.h"

char direction;


void main()
{
 setup_timer_1( T1_INTERNAL | T1_DIV_BY_1);
 setup_timer_2(T2_DIV_BY_16,250,16); //16*250*0,2u = 0,8ms para a base de tempo
  
   enable_interrupts(global);        //habilita a interrup??o global
   enable_interrupts(int_timer2);    //habilita a interrup??o de timer2, vou manter a interrup??o de timer 2
   enable_interrupts(int_rda);       //habilita interrupcao UART
   
   setup_ccp1(CCP_PWM);              //configura o CCP1 como PWM
   setup_ccp2(CCP_PWM); 
   setup_adc(ADC_CLOCK_DIV_32);   //configura conversor AD
   setup_adc_ports(AN0_AN1_AN3);          //escolhe apenas o pino A0 como entrada anal?gica
   

   while (true)            //loop de repeti??o do c?digo principal
   {

  
   direction = getc();
   
   switch(direction)
   {
      case 'W': 
      set_pwm1_duty(800);
      set_pwm2_duty(800);
      output_b(0x05);      
      break;
      
      case 'S':
      set_pwm1_duty(800);
      set_pwm2_duty(800);
      output_b(0x0A);      
      break;
      //Curvas devem ser feitas com diferenças na velocidade entre as rodas
      case 'D':
      set_pwm1_duty(800);
      set_pwm2_duty(200);
      //output_b(0x05);      
      output_b(0x06);
      break;
      
      case 'A':
      set_pwm1_duty(200);
      set_pwm2_duty(800);
      //output_b(0x05);
      output_b(0x09);
      break;
      
      case 'Q':
      set_pwm1_duty(0);
      set_pwm2_duty(0);
      output_b(0x0F);
      break;
   }
   
   }   // fim do while

}
