#include <main.h>
#include <display7seg.h>
#include <keyboard.h>
#include <typedef.h>

EKey_status keystatus;
uint8_t key_value, buffer_tail=0, display_count=0;
uint32_t debounce=0;
uint8_t buffer[6] = {0,0,0,0,0,0};

void buffer_insert(uint8_t valueToInsert)
{
  if(buffer_tail <= 5)
  {
   buffer[buffer_tail] = valueToInsert;
  }
  else
  {
    buffer_tail = 5;
   
    for(uint8_t i=5; i>0; i--)
    {
      buffer[i] = buffer[i-1]; //copy buffer 
    }
    buffer[0] = valueToInsert;
  }
  buffer_tail++;
}

void main()
{

   while(TRUE)
   {
      keystatus = key_read(key_value);
      
      if(keystatus == ANY_KEY_WAS_PRESSED)
      {
         debounce++;
         if(debounce > 0xFF)
         {
            debounce = 0;
            //if(key_value > 0xF) key_value = 0; //debug
            buffer_insert(key_value);
         }       
      }
        
      for(uint8_t i=1; i<7; i++)
      {
         displayClear();
         displayWrite(buffer[i-1],i);
      }
    
   }//end while

}//end main


