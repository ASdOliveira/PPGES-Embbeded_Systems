/****************************************************
 * 
 * Exercicio 2 - Aula 1
 * 
 * Portas A e B como saidas
 * Portas C e D como entradas
 * 
 * 2 bits da porta E como controle
 *      - Se E == 00 A recebe C, B recebe D
 *      - Se E == 01 A recebe C, B recebe C
 *      - Se E == 10 A recebe D, B recebe D
 *      - Se E == 11 A recebe D, B recebe C
 *  
 * Arysson Oliveira
 * 
 ***************************************************/

#include <16F877a.h>
#include "typedef.h"
#use delay (clock = 20000000)
#fuses HS,NOWDT, NOPROTECT, NOPUT, NOBROWNOUT, NOLVP

// Variaveis auxiliares:
uint8_t port_c = 0, port_d = 0, port_e = 0;


void main()
{
    while (true)
    {
        // Leitura das entradas:
        port_e = input_e();   
        port_c = input_c();
        port_d = input_d();
        
        // Condicao para a saida.
        switch (port_e)
        {
            case 0x00:
                output_a(port_c);
                output_b(port_d);
                break;
            
            case 0x01:
                output_a(port_c);
                output_b(port_c);
                break;
            
            case 0x02:
                output_a(port_d);
                output_b(port_d);
                break;
            
            case 0x03:
                output_a(port_d);
                output_b(port_c);
                break;
        }
    }

}

