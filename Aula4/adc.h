#ifndef _ADC_H_
#define _ADC_H_

#include<utils.h>
#include<typedef.h>

typedef struct
{
  uint8_t channel;     //channel
  ELightLvlSensor valor; //value after convertion
}TLuminositySensor;

typedef struct
{
  uint8_t ch;     //channel
  EPresenceSensor value; //value after convertion
}TPresenceSensor;

extern ELightLvlSensor luminositySensor(int16_t valor);
extern EPresenceSensor presenceSensor(int16_t value);

#endif //_ADC_H_
