#ifndef __display7seg__
#define __display7seg__

#include <16f877a.h>
#include <typedef.h>


extern void displayWrite(uint8_t digit, uint8_t displayNum);
extern void displayClear();

#endif
