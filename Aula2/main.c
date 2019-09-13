#include <main.h>
#include <keyboard.h>
#include <typedef.h>

//variaveis auxiliares
uint8_t lerTec = 0, lerTecAtual = 0;
uint8_t port = 0x01;


void main()
{
    key_init(); // configuracao inicial dos pinos do teclado matricial 4x4
   while(TRUE)
   {
    lerTec = key_read();   // ler qual tecla foi pressionada, caso nenhuma tenha sido pressionada, é retornado 0xFF.
    if(lerTec != 0xFF)     // Se alguma tecla foi lida...
    {
      lerTecAtual=lerTec;  // armazena-se o valor da tecla lida
    }     
     rotate_right(&port,1); // faz a rotacao do pino em 1 bit de deslocamento
     output_a(port);        //"exibe" o resultado no port A.
     delay_ms(lerTecAtual); //para melhorar a visualizazao, pode multiplicar por uns 4 ou 5.
   }

}


