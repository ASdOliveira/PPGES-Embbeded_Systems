#ifndef __KEYBOARD__
#define __KEYBOARD__

#include <typedef.h>

enum EKey_status
{
   ANY_KEY_WAS_PRESSED,
   NO_KEY_PRESSED
};
//prototipos das funcoes
extern void key_init();
extern EKey_status key_read(uint8_t &key_value);
EKey_status decodKey(uint8_t count, uint8_t &value);



#endif
