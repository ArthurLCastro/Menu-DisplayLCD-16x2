#include "menu.h"

MenuLcd::MenuLcd(){
}

MenuLcd::MenuLcd(byte buttonLeft, byte buttonEnter, byte buttonRight){
    setButton(buttonLeft, buttonEnter, buttonRight);
}

void MenuLcd::setButton(byte butLeft, byte butEnter, byte butRight){
    pinMode(butLeft, INPUT_PULLUP);
    pinMode(butEnter, INPUT_PULLUP);
    pinMode(butRight, INPUT_PULLUP);
}