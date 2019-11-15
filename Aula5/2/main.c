#include <main.h>
#include <typedef.h>
#include <rotinasLCD.h>
#include <int2char.h>

enum EButtonState 
{
   UP,
   DOWN,
   NONE
};

EButtonState read_button()
{
   int port_a = 0xFF;
   EButtonState return_value;
   
   port_a = input_a();
   delay_ms(150);
   
   switch(port_a)
   {
    case 0x01:
               return_value = UP;
    break;
    case 0x02:
               return_value = DOWN;
    break;
    
    default:
               return_value = NONE;
    break;
   }
   
   return return_value;
}


void main ()
{
   
   int line_0 [5] = {'A','d','d','r','='};
   int line_1 [5] = {'V','a','l',' ','='};
   
   char *converted_char;
   long int address = 0x00, memory_value = 0x00;
   
   LCD_init();
   
   while (true)            
   {
      LCD_pos_cursor (0x00);     //posiciona cursor na linha 0, coluna 0
      LCD_WRITE_STRING(line_0, 5); //escreve sequencia 1
      LCD_pos_cursor (0x10);     //posiciona cursor na linha 0, coluna 0
      LCD_WRITE_STRING(line_1, 5); //escreve sequencia 1
      
      switch (read_button())
      {
         case UP: 
                  address++;
                  if(address >= 0x1FFF) address = 0;
         break;
         
         case DOWN:
                  address--;
                  if(address <= 0) address = 0x1FFF;
         break;
      }
      
      memory_value = read_program_eeprom(address);
      converted_char = int2char(address,5);
      
      LCD_pos_cursor (0x06);
      LCD_WRITE_STRING(converted_char,5);
      
      converted_char = int2char(memory_value,5);
      LCD_pos_cursor (0x16);      //posiciona cursor na linha 1, coluna 0
      LCD_WRITE_STRING(converted_char, 5); //escreve sequencia 2
   
   }   // fim do while
}      // fim do main


