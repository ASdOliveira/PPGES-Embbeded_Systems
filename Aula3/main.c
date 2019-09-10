#include <main.h>
#include <display7seg.h>
#include <typedef.h>

uint8_t counter = 0, time = 0, dezena = 0, unidade = 0;

#INT_TIMER0                  //a fun??o que estiver aqui dentro vai rodar quando ocorrer a interrup??o
void timer0 ()
{
  counter++; // incrementado a cada 13,1072ms para prescaler de 256
  
   if((counter%2) == 0)
      {
         
         displayWrite(dezena,1);
         
      }
      else
      {
        displayWrite(unidade,2);
      }
}



void main()
{
  //configuracao do timer
   Setup_timer_0(rtcc_internal | RTCC_DIV_256);    //configura o timer zero com o preescaler de 1:256
   set_timer0(0);                           //inicializa o timer0 com 0
   enable_interrupts(GLOBAL);                //habilita as interrrupcoes
   enable_interrupts(INT_TIMER0);
   
   while(TRUE)
   {
      if(counter >= 77) // aproximadamente 1seg 77
      {
         counter = 0;
         time++;
         
         if(time >=60)
         {
            time = 0;
         }
         dezena = time/10;
         unidade = time%10;
      }
      
     
      
   }

}
