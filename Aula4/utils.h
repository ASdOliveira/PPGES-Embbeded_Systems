#ifndef _UTILS_H_
#define _UTILS_H_

#include <16F877A.h> // NAO FAZ SENTIDO TER AQUI. MAS O COMPILADOR EXIGIU!
enum ELightLvlSensor  //Luminosity sensor (ambient)
{
   HIGH_LVL_LIGHT,
   INTERMEDIATE_LVL_LIGHT,
   LOW_LVL_LIGHT
};

enum EPresenceSensor
{
   SENSOR_ON,
   SENSOR_OFF
};

enum ELightStatus //Light status (Load)
{
   LIGHT_ON,
   LIGHT_OFF
};




#endif //_UTILS_H_
