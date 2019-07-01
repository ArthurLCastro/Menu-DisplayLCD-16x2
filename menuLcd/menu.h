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

    public:
        MenuLcd();          //Construtor Padrão
        MenuLcd(byte, byte, byte);
        void setOpcoes(byte, String[]);
        void setupMenu(LCD&);
        void setButton(byte, byte, byte);
        byte navegarMenu();
};