#pragma once

#include <Arduino.h>
#include <LCD.h>

#define QTD_MAX_OPCOES 10

class MenuLcd{
    private:
  		LCD *display;
        byte botaoL, botaoE, botaoR;
        byte qtdOpcoes = 0;
        String opcaoLinhas[QTD_MAX_OPCOES];
        byte qtdTelas = 0;
        byte indexLcd = 0;
        byte resto = 0;
        bool sairMenu = 0;
        bool indexCursor = 0;
        bool atualizar = true;
        void estadoBotoes();
        void atualizaMenu();
        byte setaDireita[8] = {
          0b00000,
          0b00100,
          0b00010,
          0b11111,
          0b00010,
          0b00100,
          0b00000,
          0b00000
        };
 
    public:
        MenuLcd();          //Construtor Padrão
        MenuLcd(byte, byte, byte);
        void setOpcoes(byte, String[]);
        void setupMenu(LCD&);
        void setButton(byte, byte, byte);
        byte navegarMenu();
};