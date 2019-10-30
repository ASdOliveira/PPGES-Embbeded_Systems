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

void LCD_INIT ();
void LCD_CLEAR ();
void LCD_WRITE_CHAR(char letra);
void LCD_WRITE_STRING (CHAR LOCAL [32], int cont);
void LCD_CURSOR_DISABLE ();
void LCD_CURSOR_ENABLE ();
void LCD_shift (cursorPosition mode);
void LCD_pos_cursor (int pos);