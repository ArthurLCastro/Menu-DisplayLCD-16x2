// Menu de navegação com Display LCD 16x2 e pushbuttons
// Arthur L. Castro
// Junho de 2019

#include <LiquidCrystal_I2C.h>

#define BUT_ENTER 2         // Pino de Interrupção para Botão de Enter/Menu
#define BUT_LEFT 6          // Pino para botão de navegação para a esquerda
#define BUT_RIGHT 7         // Pino para botão de navegação para a direita
#define BUZZER 10

LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int contador;

String opcao[] = {"Opcao 0", "Opcao 1", "Opcao 2", "Opcao 3", "Opcao 4", "Opcao 5"};
byte qtdOpcoes = 6, qtdTelas = 0, indexLcd = 0, resto = 0;
bool sairMenu = 1, indexCursor = 0, atualizar = true;

void setup() {
  lcd.begin(16,2);
  delay(1);
  lcd.setCursor(0,0);
  lcd.print("  Iniciando...  ");
  delay(500);
  
  Serial.begin(9600);                       // Inicia a comunicação Serial a uma taxa de transmissão de 9600

  pinMode(BUZZER, OUTPUT);
  pinMode(BUT_LEFT, INPUT_PULLUP);
  pinMode(BUT_ENTER, INPUT_PULLUP);
  pinMode(BUT_RIGHT, INPUT_PULLUP);
  
  contador = 0;
}

void loop() {
  menu();
  delay(5000);
/*  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Rodando o loop ");
  lcd.setCursor(0,1);
  lcd.print("Contador: ");
  lcd.print(contador);
  contador++;
  delay(1000);
*/
}

void menu(){
  apresentacaoMenu();
  delay(2000);
  telaMenu();
}

void apresentacaoMenu(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("----- MENU -----");  
}

void telaMenu(){  
  qtdTelas = qtdOpcoes / 2;
  resto = qtdOpcoes % 2;
  if(resto > 0){
      qtdTelas++;
  }

  while(sairMenu){
    estadoBotoes();
    if(atualizar == true){
      Serial.println("Atualizando Display");
      atualizaMenu();
      atualizar = false;
    }
    delay(50);
  }
}

bool estadoBotoes(){
  bool butL, butE, butR;

  butL = digitalRead(BUT_LEFT);
  butE = digitalRead(BUT_ENTER);
  butR = digitalRead(BUT_RIGHT);
  delay(50);

  if((butR == LOW) && (indexLcd < (qtdOpcoes-1))){
    atualizar = true;
    indexLcd++;
  }
  if((butL == LOW) && (indexLcd > 0)){
    atualizar = true;
    indexLcd--;
  }
  if(butE == LOW){
    atualizar = true;
    subMenu(indexLcd);
  }

  Serial.print("indexLcd: ");
  Serial.println(indexLcd);
  
  return atualizar;
}

void atualizaMenu(){
  byte j = 0;
  for(byte i=0; i<qtdTelas; i++){
    if((resto > 0) && (i == (qtdTelas-1))){
      if((indexLcd == j) || (indexLcd == (j+1))){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("  " + opcao[j]);
        lcd.setCursor(0,1);
        lcd.print("                ");
      }
    } else {
      if((indexLcd == j) || (indexLcd == (j+1))){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("  " + opcao[j]);
        lcd.setCursor(0,1);
        lcd.print("  " + opcao[j+1]);
      }
    }
    j=j+2;
  }
  
  if((indexLcd % 2) == 0){
    indexCursor = 0;
  } else {
    indexCursor = 1;
  }
  lcd.setCursor(0, indexCursor);
  lcd.print("> ");
  lcd.setCursor(0, !indexCursor);
  lcd.print("  ");
}

void subMenu(byte opcaoSelecionada){
  switch(opcaoSelecionada){
    case 0:
//      telaopcao0();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("  Tela Opcao 0  ");
      delay(2000);
      break;
    case 1:
//      telaopcao1();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("  Tela Opcao 1  ");
      delay(2000);
      break;
    case 2:
//      telaopcao2();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("  Tela Opcao 2  ");
      delay(2000);
      break;
// ...
  }
}
