//Programa para exemplificar o uso de displays LCDs alfanum?ricos

//O programa ir? ler 2 tens?es vindas de 2 potenci?metros conectados a 2 canais anal?gico-digitais
//e mostrar? as duas tens?es convertidas nas duas linhas do display

/*Coment?rios sobre o LCD no arquivo rotinasLCD.c
*/

/*Fun??es ?teis para a manipula??o de bits

bit_clear(var, bit)  //zera o bit especificado
bit_set(var, bit)    //seta o bit especificado
value = bit_test (var, bit)  //testa o bit especificado
*/

#include <main.h>
#use delay(crystal=20000000)
#include <rotinasLCD.h>
#include <int2char.h>
#include <typedef.h>

void main ()
{

int stat1 [16] = {'P','o','t','.',' ',' ','1',' ','='};
int stat2 [16] = {'P','o','t','.',' ',' ','2',' ','='};
char *converted_char;

   setup_adc(ADC_CLOCK_DIV_32);   //configura conversor AD
   setup_adc_ports(AN0_AN1_AN3);   //escolhe pinos de entradas anal?gicas
   
   //por algum motivo desconhecido o compilador n deixa declarar vari?veis ap?s essas configura??es
   
   LCD_init();

   while (true)            //loop de repeti??o do c?digo principal
   {
      long int AD;
      //ler tens?o no canal zero
      set_adc_channel(0);      //escolhe canal
      delay_ms(50);            //espera um tempo para a tens?o se estabilizar
      AD = read_adc();        //inicia a convers?o, espera ela ser concluida e retorna o valor convertido  
      converted_char = int2char(AD);
      //aqui teria que ser feito o tratamento do valor recebido para 
      //converter o numero para ascii e imprimir no LCD
      //sem saco p fazer isso agora
      //quem sabe um dia ??????????????
      
      LCD_pos_cursor (0x00);     //posiciona cursor na linha 0, coluna 0
      LCD_WRITE_STRING(stat1, 9); //escreve sequencia 1
      LCD_pos_cursor (0x0A);
      LCD_WRITE_STRING(converted_char,4);
      LCD_pos_cursor (0x10);      //posiciona cursor na linha 1, coluna 0
      LCD_WRITE_STRING(stat2, 9); //escreve sequencia 2
      
      delay_ms(1000);
      

      //ler tens?o no canal um
      set_adc_channel(1);      //escolhe canal
      delay_ms(50);            //espera um tempo para a tens?o se estabilizar
      AD = read_adc();        //inicia a convers?o, espera ela ser concluida e retorna o valor convertido
      *converted_char = int2char(AD);
      LCD_pos_cursor (0x1A);
      LCD_WRITE_STRING(converted_char,4);
      //aqui teria que ser feito o tratamento do valor recebido para 
      //converter o numero para ascii e imprimir no LCD
      //sem saco p fazer isso agora
      //quem sabe um dia ??????????????

      

      delay_ms(1000);
     
   }   // fim do while
}      // fim do main

