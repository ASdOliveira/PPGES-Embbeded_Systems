#include <int2char.h>
#include <math.h>

/*
 The reason is:
 if you want to separe the number 1023,
 you can divide:
 1023/(1000 = 10^3) = 1
 1023/(100 = 10^2) = 0
 1023/(10 = 10^1) = 2
 1023/(1 = 10^0) = 3

*/

char *int2char(long int value, int8_t max_count)
{
   static char converted_char[5];
   
   long long y=1;
   for (int j=0; j<(max_count-1); j++)
   {
      y = y*10;
   }
   
   for(int i=0; i<max_count; i++)
   {
      //long long y = (pow(10,((max_count-1) - i)));
      converted_char[i] = (48 + value/y);
      value = value%y;
      y = y/10;
   }
   return converted_char;
}

/*
char *int2char (long int number)
{
  static char tmp[4];

  tmp[0] = makedigit(&number, 1000);
  tmp[1] = makedigit(&number, 100);
  tmp[2] = makedigit(&number, 10);
  tmp[3] = makedigit(&number, 1);
  //tmp[5] = '\0';

  return tmp;
}

char makedigit (long int *number, int base)
{
  static char map[] = "0123456789";
  int ix;

  for (ix=0; *number >= base; ix++) { *number -= base; }

  return map[ix];
}

*/





