#include <main.h>
#include <display7seg.h>
#include <keyboard.h>
#include <typedef.h>

EKey_status keystatus;
uint8_t key_value, buffer_tail=0;
uint8_t buffer[6] = {0,0,0,0,0,0};

void buffer_insert(uint8_t &valueToInsert)
{
  buffer_tail++;
  if(buffer_tail < 5)
  {
   buffer[buffer_tail] = valueToInsert;
  }
  else
  {
    buffer_tail = 5;
   
    for(uint8_t i=0; i<5; i++)
    {
      buffer[i] = buffer[i+1]; //copy buffer 
    }
    buffer[buffer_tail] = valueToInsert;
  }
}

void main()
{

   while(TRUE)
   {
      keystatus = key_read(key_value);
      
      if(keystatus == ANY_KEY_WAS_PRESSED)
      {
         buffer_insert(key_value);        //atualiza o buffer
      }
      
      for(uint8_t i=0; i<7; i++)
      {
         displayWrite(buffer[i],i);
      }
      
      
   }//end while

}//end main


