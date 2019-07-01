// Exemplo de uso do Menu de navegação com Display LCD 16x2 e 3 pushbuttons
// Arthur L. Castro
// Junho de 2019

#include "menu.h"
#include <LiquidCrystal_I2C.h>

#define BUT_ENTER   2         // Pino para botão de selecao
#define BUT_LEFT    6          // Pino para botão de navegação para a esquerda
#define BUT_RIGHT   7         // Pino para botão de navegação para a direita

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
MenuLcd meuMenu1(BUT_LEFT, BUT_ENTER, BUT_RIGHT);

String definindoOpcoes[] = {"Opcao 0", "Opcao 1", "Opcao 2", "Opcao 3", "Opcao 4", "Opcao 5", "Opcao 6"};
byte quantidOpcoes = 7, opcaoSelecionada = 0;

void setup() {
    lcd.begin(16,2);
    delay(1);

    lcd.setCursor(0,0);
    lcd.print("   Iniciando    ");
    lcd.setCursor(0,1);
    lcd.print("   Sistema...   ");
    delay(500);
    
    meuMenu1.setupMenu(lcd);
    meuMenu1.setOpcoes(quantidOpcoes, definindoOpcoes);
//    meuMenu1.setButton(BUT_LEFT, BUT_ENTER, BUT_RIGHT);

    Serial.begin(9600);                       // Inicia a comunicação Serial a uma taxa de transmissão de 9600
}

void loop() {
    apresentacao("   Meu Menu 1   ");
    opcaoSelecionada = meuMenu1.navegarMenu();
    subMenu(opcaoSelecionada);
}

void apresentacao(String texto){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(texto);
    delay(2000);
}

void subMenu(byte escolhida){
    switch(escolhida){
        case 0:
            // Você pode criar aqui um funcao como "telaopcao0();" para ser executada ou fazer como o exemplo abaixo: 
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("  Tela Opcao 0  ");
            delay(2000);
            break;
        case 1:
            // Você pode criar aqui um funcao como "telaopcao1();" para ser executada ou fazer como o exemplo abaixo: 
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("  Tela Opcao 1  ");
            delay(2000);
            break;
        case 2:
            // Você pode criar aqui um funcao como "telaopcao2();" para ser executada ou fazer como o exemplo abaixo: 
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("  Tela Opcao 2  ");
            delay(2000);
            break;
        case 3:
            // Você pode criar aqui um funcao como "telaopcao3();" para ser executada ou fazer como o exemplo abaixo: 
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("  Tela Opcao 3  ");
            delay(2000);
            break;
        case 4:
            // Você pode criar aqui um funcao como "telaopcao4();" para ser executada ou fazer como o exemplo abaixo: 
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("  Tela Opcao 4  ");
            delay(2000);
            break;
        case 5:
            // Você pode criar aqui um funcao como "telaopcao5();" para ser executada ou fazer como o exemplo abaixo: 
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("  Tela Opcao 5  ");
            delay(2000);
            break;
        case 6:
            // Você pode criar aqui um funcao como "telaopcao6();" para ser executada ou fazer como o exemplo abaixo: 
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("  Tela Opcao 6  ");
            delay(2000);
            break;
        case 7:
            // Você pode criar aqui um funcao como "telaopcao7();" para ser executada ou fazer como o exemplo abaixo: 
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("  Tela Opcao 7  ");
            delay(2000);
            break;
        // ...
        default:
            lcd.clear();
            delay(2000);
            break;
    }
}