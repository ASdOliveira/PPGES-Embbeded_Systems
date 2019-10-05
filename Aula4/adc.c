#include<adc.h>


/*
Considering a 10bits ADC,
 MAX LEVEL > 800 
 INTERMEDIATE BETWEEN 400 AND 800
 MIN LEVEL < 400
*/

#define MAX_THRESHOLD   800 //3,9V
#define MIN_THRESHOLD   400 //1,95V
#define TOUCH_THRESHOLD 50 //0,24V

ELightLvlSensor luminositySensor(int16_t valor)
{
   if (valor >= MAX_THRESHOLD)
   {
      return HIGH_LVL_LIGHT;
   }
   else if (valor <= MIN_THRESHOLD)
   {
      return LOW_LVL_LIGHT;
   }
   else
   {
      return INTERMEDIATE_LVL_LIGHT;
   }
}

EPresenceSensor presenceSensor(int16_t value)
{
 if (value >= TOUCH_THRESHOLD)
 {
   return SENSOR_ON;
 }
 
 else
 {
   return SENSOR_OFF;
 }
}
