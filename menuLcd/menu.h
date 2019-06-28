#pragma once
#include <Arduino.h>

class MenuLcd{
    private:
        byte qtdTelas = 0,
             indexLcd = 0,
             resto = 0;
        bool sairMenu = 0,
             indexCursor = 0,
             atualizar = true;

    public:
        MenuLcd();      //Construtor Padrão
        MenuLcd(byte, byte, byte);
        void setButton(byte, byte, byte);
        void apresentacaoMenu(String nomeMenu);
        void iniciarMenu();
        void estadoBotoes();
        void atualizaMenu();
        void subMenu(byte opcaoSelecionada);
};