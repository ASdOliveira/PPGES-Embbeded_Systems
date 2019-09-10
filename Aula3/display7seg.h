#ifndef __display7seg__
#define __display7seg__

#include <typedef.h>

/*
   funcoes fornecidas pelo professor na aula 03
*/

const int D7seg0 = 0b11111100; //m?scara para escrever 0 no display de 7 segmentos
const int D7seg1 = 0b01100000; //m?scara para escrever 1 no display de 7 segmentos
const int D7seg2 = 0b11011010; //m?scara para escrever 2 no display de 7 segmentos
const int D7seg3 = 0b11110010; //m?scara para escrever 3 no display de 7 segmentos
const int D7seg4 = 0b01100110; //m?scara para escrever 4 no display de 7 segmentos
const int D7seg5 = 0b10110110; //m?scara para escrever 5 no display de 7 segmentos
const int D7seg6 = 0b10111110; //m?scara para escrever 6 no display de 7 segmentos
const int D7seg7 = 0b11100000; //m?scara para escrever 7 no display de 7 segmentos
const int D7seg8 = 0b11111110; //m?scara para escrever 8 no display de 7 segmentos
const int D7seg9 = 0b11110110; //m?scara para escrever 9 no display de 7 segmentos
const int D7segA = 0b11101110; //m?scara para escrever A no display de 7 segmentos
const int D7segb = 0b00111110; //m?scara para escrever B no display de 7 segmentos
const int D7segC = 0b10011100; //m?scara para escrever C no display de 7 segmentos
const int D7segD = 0b01111010; //m?scara para escrever D no display de 7 segmentos
const int D7segE = 0b10011110; //m?scara para escrever E no display de 7 segmentos
const int D7segF = 0b10001110; //m?scara para escrever F no display de 7 segmentos

int mask7seg (int a) //fun??o para converter um inteiro de 0 a 15 na sua m?scara 
               //para um display de 7 segmentos
{
   int mask;
   switch (a) 
   {
      case 0:   mask = d7seg0;
            break;
      case 1:   mask = d7seg1;
            break;
      case 2:   mask = d7seg2;
            break;
      case 3:   mask = d7seg3;
            break;
      case 4:   mask = d7seg4;
            break;
      case 5:   mask = d7seg5;
            break;
      case 6:   mask = d7seg6;
            break;
      case 7:   mask = d7seg7;
            break;
      case 8:   mask = d7seg8;
            break;
      case 9:   mask = d7seg9;
            break;
      case 0xA :   mask = d7segA;
            break;
      case 0xb:   mask = d7segb;
            break;
      case 0xC:   mask = d7segC;
            break;
      case 0xd:   mask = d7segD;
            break;
      case 0xE:   mask = d7segE;
            break;
      case 0xF:   mask = d7segF;
            break;
   }
   return mask;
}

void displayWrite(uint8_t digit, uint8_t displayNum)
{
   
   switch(displayNum)
   { // display é acesso com 0...
     case 1: output_a(0b11111110); break;
     case 2: output_a(0b11111101); break;
     case 3: output_a(0b11111011); break;
     case 4: output_a(0b11110111); break;
     default: output_a(0xFF); break;
   }
   output_b(mask7seg(digit));
}

void displayClear()
{
   output_a(0xFF);
}

#endif
