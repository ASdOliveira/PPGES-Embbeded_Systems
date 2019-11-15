#ifndef __LCDROUTINE__
#define __LCDROUTINE__

#include <16F877A.h>
/*
#define CursorRight  1
#define CursorLeft   2
#define DisplayRight 3
#define DisplayLeft  4
*/

extern enum cursorPosition{
    CURSOR_RIGHT,
    CURSOR_LEFT,
    DISPLAY_RIGHT,
    DISPLAY_LEFT
};

extern void LCD_INIT ();
extern void LCD_CLEAR ();
extern void LCD_WRITE_CHAR(char letra);
extern void LCD_WRITE_STRING (CHAR LOCAL [32], int cont);
extern void LCD_CURSOR_DISABLE ();
extern void LCD_CURSOR_ENABLE ();
extern void LCD_shift (cursorPosition mode);
extern void LCD_pos_cursor (int pos);

#endif
