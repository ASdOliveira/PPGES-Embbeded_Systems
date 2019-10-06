#include <main.h>
#include <keyboard.h>
#include <typedef.h>

//variaveis auxiliares
uint8_t lerTecAtual = 0;
uint8_t port = 0x01;
uint8_t value = 0;
EKey_status lerTec = NO_KEY_PRESSED;


void main()
{
    key_init(); // configuracao inicial dos pinos do teclado matricial 4x4
   while(TRUE)
   {
    lerTec = key_read(value);   // ler qual tecla foi pressionada, caso nenhuma tenha sido pressionada, é retornado 0xFF.
    if(lerTec == ANY_KEY_WAS_PRESSED)     // Se alguma tecla foi lida...
    {
      lerTecAtual=value;  // armazena-se o valor da tecla lida
    }     
     rotate_right(&port,1); // faz a rotacao do pino em 1 bit de deslocamento
     output_a(port);        //"exibe" o resultado no port A.
     delay_ms(lerTecAtual); //para melhorar a visualizazao, pode multiplicar por uns 4 ou 5.
   }

}


