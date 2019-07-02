#include "menu.h"

// #define DEBUG

MenuLcd::MenuLcd(){
}

MenuLcd::MenuLcd(byte buttonLeft, byte buttonEnter, byte buttonRight){
    setButton(buttonLeft, buttonEnter, buttonRight);
}

void MenuLcd::setupMenu(LCD& liquidI2C){
  this->display = &liquidI2C;
  display->createChar(1, setaDireita);
  display->begin(16, 2);

}

void MenuLcd::setButton(byte butLeft, byte butEnter, byte butRight){
    botaoL = butLeft;
    botaoE = butEnter;
    botaoR = butRight;

    pinMode(botaoL, INPUT_PULLUP);
    pinMode(botaoE, INPUT_PULLUP);
    pinMode(botaoR, INPUT_PULLUP);
}

void MenuLcd::setOpcoes(byte nOpcoes, String opcoes[]){
    for(byte i=0; i<nOpcoes; i++){
      opcaoLinhas[i] = opcoes[i];
    }
    qtdOpcoes = nOpcoes;

    qtdTelas = qtdOpcoes / 2;
    resto = qtdOpcoes % 2;
    if(resto > 0){
        qtdTelas++;
    }
}

byte MenuLcd::navegarMenu(){
    while(!sairMenu){
        estadoBotoes();
        if(!sairMenu == true){
            if(atualizar == true){
                #ifdef DEBUG
                    Serial.println("Atualizando Display");
                #endif
                atualizaMenu();
                atualizar = false;
            }
        }
    }
    sairMenu = false;
    return indexLcd;
}

void MenuLcd::estadoBotoes(){
  bool estadoButL, estadoButE, estadoButR;

  estadoButL = digitalRead(botaoL);
  estadoButE = digitalRead(botaoE);
  estadoButR = digitalRead(botaoR);
  delay(50);

  if((estadoButR == LOW) && (indexLcd < (qtdOpcoes-1))){
    atualizar = true;
    indexLcd++;
  }
  if((estadoButL == LOW) && (indexLcd > 0)){
    atualizar = true;
    indexLcd--;
  }
  if(estadoButE == LOW){
    atualizar = true;
    sairMenu = true;
  }

  #ifdef DEBUG
    Serial.print("indexLcd: ");
    Serial.println(indexLcd);
  #endif
}

void MenuLcd::atualizaMenu(){
  byte j = 0;
  for(byte i=0; i<qtdTelas; i++){
    if((resto > 0) && (i == (qtdTelas-1))){
      if((indexLcd == j) || (indexLcd == (j+1))){
        display->clear();
        display->setCursor(0,0);
        display->print("  " + opcaoLinhas[j]);
        display->setCursor(0,1);
        display->print("                ");
      }
    } else {
      if((indexLcd == j) || (indexLcd == (j+1))){
        display->clear();
        display->setCursor(0,0);
        display->print("  " + opcaoLinhas[j]);
        display->setCursor(0,1);
        display->print("  " + opcaoLinhas[j+1]);
      }
    }
    j=j+2;
  }
  
  if((indexLcd % 2) == 0){
    indexCursor = 0;
  } else {
    indexCursor = 1;
  }
  display->setCursor(0, indexCursor);
  display->write((byte)1);
  display->setCursor(0, !indexCursor);
  display->print("  ");
}