#include<light.h>




void light(uint8_t PIN, ELightStatus status)
{
   if(status == LIGHT_ON)
   {
      output_bit(PIN,1);
   }
   else
   {
      output_bit(PIN,0);
   }
}

