#include "joystick.h"

#define MAX_THRESHOLD 550
#define MIN_THRESHOLD 500

//Priorizando fazer curvas à ir pra frente / tras.

EDirections joystick (long int &pot1,long int &pot2)
{
   if(pot2 > MAX_THRESHOLD)
   {
      return DIREITA;
   }
   else if(pot2 < MIN_THRESHOLD)
   {
      return ESQUERDA;
   }
   else
   {
      if(pot1 > MAX_THRESHOLD)
      {
         return FRENTE;
      }
      else if(pot1 < MIN_THRESHOLD)
      {
         return TRAS;
      }
      else
      {
         return PARAR;
      }
   }
}

