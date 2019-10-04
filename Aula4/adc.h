#ifndef _ADC_H_
#define _ADC_H_

#include<utils.h>
#include<typedef.h>

typedef struct
{
  uint8_t ch;     //channel
  uint16_t value; //value after convertion
}Tadc;


ELightLvlSensor luminositySensor(uint16_t value);
EPresenceSensor presenceSensor(uint16_t value);

#endif //_ADC_H_
