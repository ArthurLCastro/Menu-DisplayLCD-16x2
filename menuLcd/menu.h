#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class MenuLcd{
    private:
  		LiquidCrystal_I2C *display;
        byte botaoL, botaoE, botaoR;
        byte qtdOpcoes = 0;
        String opcaoLinhas[];
        byte qtdTelas = 0;
        byte indexLcd = 0;
        byte resto = 0;
        bool sairMenu = 0;
        bool indexCursor = 0;
        bool atualizar = true;
        void setupMenu(LiquidCrystal_I2C&);
        void estadoBotoes();
        void atualizaMenu();

    public:
        MenuLcd();          //Construtor Padrão
        MenuLcd(byte, byte, byte);
        void setButton(byte, byte, byte);
        byte navegarMenu();
};