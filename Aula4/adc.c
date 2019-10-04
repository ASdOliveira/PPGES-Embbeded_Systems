#include<adc.h>


/*
Considering a 10bits ADC,
 MAX LEVEL > 800 
 INTERMEDIATE BETWEEN 400 AND 800
 MIN LEVEL < 400
*/

#define MAX_THRESHOLD   800
#define MIN_THRESHOLD   800
#define TOUCH_THRESHOLD 200

ELightLvlSensor luminositySensor(uint16_t value)
{
   if (value > MAX_THRESHOLD)
   {
      return HIGH_LVL_LIGHT;
   }
   else if (value < MIN_THRESHOLD)
   {
      return LOW_LVL_LIGHT;
   }
   else
   {
      return INTERMEDIATE_LVL_LIGHT;
   }
}

EPresenceSensor presenceSensor(uint16_t value)
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
