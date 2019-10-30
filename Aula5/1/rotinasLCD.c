#include <rotinasLCD.h>

//Arquivo com rotinas para a utiliza��o do LCD

/*O LCD alfanum�rico utilizado possui 2 linhas e 16 colunas
o barramento de dados est� ligado na porta D
e o barramento de controle est� ligado na porta E
*/


/* Esta rotina inicializa o display de cristal liquido.
Ser�o utilizadas 8 vias de comunica��o, entre outras
op��es do display que s�o detalhadas abaixo.*/
void LCD_INIT () //m�todo que inicializa o LCD
{
   //i) delay de pelo menos 15 ms ap�s alimenta��o     
   delay_ms(15);
   
   output_low (pin_e1); //set R/W to 0 = write
   
   //ii) enviar comand 0x30 para o display. Mexendo com mem�ria CG RAM
   output_low (pin_e2); //RS = 0, RS = Register Select, 0 -> instru��o; 1 -> dados
   output_d(0x30);
   //enviar
   output_high (pin_e0);
   output_low (pin_e0);
   
   //iii) aguardar pelo menos 4 ms
   delay_ms(4);
   
   //iv) enviar comand 0x30 para o display
   output_low (pin_e2);
   output_d(0x30);
   //enviar
   output_high (pin_e0);
   output_low (pin_e0);
   
   //v) aguardar pelo menos 100 us
   delay_ms(1);
   
   //vi) enviar (novamente) comand 0x30 para o display
   output_low (pin_e2);
   output_d(0x30);         //0b00110000
   //enviar
   output_high (pin_e0);
   output_low (pin_e0);
   
   //vii) aguardar pelo menos 40 us
   delay_ms(1);
   
   //viii) condi��es de utiliza��o. Neste caso ser� 8 vias, com
   //      display de 2 linhas e matriz de characteres 7x5
   //RS j� � zero neste momento
   output_d(0x38);         //0b00111000
   //enviar
   output_high (pin_e0);
   output_low (pin_e0);
   
   //ix) aguardar pelo menos 40 us
   delay_ms(1);
   
   //x) limpar display e posicionar cursor na posi��o (1, 1)
   //RS j� � zero
   output_d(0x01);
   //enviar
   output_high (pin_e0);
   output_low (pin_e0);
   
   //xi) aguardar pelo menos 1.8 ms
   delay_ms(2);
   
   //xii) enviar comando que liga o display com cursor piscando
   //RS j� � zero
   output_d(0x0f);
   //enviar
   output_high (pin_e0);
   output_low (pin_e0);
   
   //xiii) aguardar pelo menos 40 us
   delay_ms(1);
   
   //xiv) comando para estabelecer modo de opera��o.
   //     deslocamento automatico de cursor para a direita
   //RS j� � zero
   output_d(0b00000110);
   //enviar
   output_high (pin_e0);
   output_low (pin_e0);
   
   //xv) aguardar pelo menos 40 us
   delay_ms(1);
}

/*Esta rotina limpa os 32 espa�os do LCD e posiciona o cursor na primeira
posi��o.*/
void LCD_CLEAR ()
{
   output_low (pin_e2); //RS = 0, enviar instru��o
   output_low (pin_e1); //r(/W) = 0, escrita
   output_d (0x01);
   output_high (pin_e0);
   output_low (pin_e0);
   // Aguarde 1.6 ms. Este trecho � necess�rio para a limpeza da tela ser
   //    concluida. Porem, este trecho pode ser removido para ganhar tempo para
   //    processamento de outras coisas enquanto a tela limpa.
   delay_ms (2);
}

/* Esta rotina escreve um caractere no LCD. O LCD deve estar inicializado e
pronto para usar.

 @entrada - simbolos no formato 'A', 'B', 'C'.. '1', '2'.. '@' (ASCII)

caso o cursor atinja o final da linha as informal��es escritas ser�o perdidas.
*/
void LCD_WRITE_CHAR(char letra)
{
   output_high (pin_e2); //RS = 1
   output_low (pin_e1); //r(/W) = 0, escrita
   output_d(letra);
   //enviar
   output_high (pin_e0);
   output_low (pin_e0);
   delay_ms(1);         //TODO: testar temporiza��es menores
}

/*Fun��o para escrever um string no LCD a partir do ponto onde o cursor estiver
Capacidade m�xima de 32 caracteres (m�ximo do LCD), se o cursor atingir o final de uma linha 
ele seguir� para o in�cio da linha seguinte.
TODO: como recuperar a posi��o do cursor
TODO: como fazer ele passar para a linha de baixo*/
void LCD_WRITE_STRING (char LOCAL [32], int cont)
{
   int local1;
   for (local1 = 0; local1 <= cont-1; local1++)
   {  
      LCD_WRITE_CHAR (LOCAL [local1]);
   }
}

/*Fun��o para desabilitar o cursor*/
void LCD_CURSOR_DISABLE ()
{
   output_low (pin_e2); //RS = 0, enviar instru��o
   output_low (pin_e1); //r(/W) = 0, escrita
   output_d (0b00001100);
   //enviar
   output_high (pin_e0);
   output_low (pin_e0);
   delay_us (100);
}

/*Fun��o para habilitar o cursor*/
void LCD_CURSOR_ENABLE ()
{
   output_low (pin_e2); //RS = 0, enviar instru��o
   output_low (pin_e1); //r(/W) = 0, escrita
   output_d (0b00001111);
   //enviar
   output_high (pin_e0);
   output_low (pin_e0);
   delay_us (100);
}
/* // ARYSSON
#define CursorRight  1
#define CursorLeft   2
#define DisplayRight 3
#define DisplayLeft  4
*/
/*Desloca o cursor ou o dysplay de uma casa de acordo com o par�metro passado
1- Cursor shift right  - CursorRight   //palavra de comando 0001 01xx
2- Cursor shift left  - CursorLeft     //palavra de comando 0001 00xx
3- display shift right (o texto inteiro anda p a esquerda)- DisplayRight  //palavra de comando 0001 11xx
4- display shift left - DisplayLeft    //palavra de comando 0001 10xx

esses par�metros est�o definidos como constantes*/
void LCD_shift (cursorPosition mode)
{
   output_low (pin_e2); //rs = 0, enviar instru��o
   output_low (pin_e1); //r(/W) = 0, escrita
   switch (mode)
   {
      case CURSOR_RIGHT:
       output_d(0b00010100); 
       //enviar
       output_high (pin_e0);
       output_low (pin_e0);
       break;
      case CURSOR_LEFT:
       output_d(0b00010000); 
       //enviar
       output_high (pin_e0);
       output_low (pin_e0);
       break;
      case DISPLAY_RIGHT:
       output_d(0b00011100); 
       //enviar
       output_high (pin_e0);
       output_low (pin_e0);
       break;
      case DISPLAY_LEFT:
       output_d(0b00011000); 
       //enviar
       output_high (pin_e0);
       output_low (pin_e0); 
       break;
   }
   delay_us (100);
}

/*Fun��o para posicionamento do cursor TODAS AS POSI��ES EM HEXADECIMAL

comando para posicionar cursor, RS = 0, r(/w) = 0
D7 D6 D5 D4 D3 D2 D1 D0
1  " -cursor address- "

o LCD possui um mapa para o posicionamento do cursor (cursor address)
00 - 0F  -- Linha 1, colunas de 0 a 15
40 - 4F  -- Linha 2, colunas de 0 a 15

Nessa fun��o � feito um mapeamento para facilitar a identifica��o de linha e coluna

Linha 0 = 00 - 0F
linha 1 = 10 - 1F
*/
void LCD_pos_cursor (int pos)
{
   output_low (pin_e2); //rs = 0, enviar instru��o
   output_low (pin_e1); //r(/W) = 0, escrita
   
   if (bit_test(pos,4))
     pos = pos + 0b10110000;
   else
     pos = pos + 0b10000000;
     
   output_d(pos); 
       //enviar
   output_high (pin_e0);
   output_low (pin_e0);
   delay_us (100);
}
