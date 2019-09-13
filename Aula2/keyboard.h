#ifndef __KEYBOARD__
#define __KEYBOARD__

#include <typedef.h>


//prototipos das funcoes
extern void key_init();
extern uint8_t key_read();
extern uint8_t decodKey(uint8_t count);

#endif
