/* placar de pontuações.32º projeto.linguagem utilizada c++

  criado por: Leonardo de Oliveira Prado
  Instagram: arduino2.0tecnologico

  Data de inicio do projeto 10/10/2023
  Data de término do projeto 10/10/2023

*/
//****************inclusão das bibliotecas
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
//****************inclusão das variáveis
int jogador_1=0;
int jogador_2=0;

int fin_de_jogo=0;
//****************definições
#define botao_joga_1 2
#define botao_joga_2 3
#define pin_bazzer 4
#define botao_finalizar 5

#define endereco 0x27 
#define colunas 16
#define linhas 2
//****************instanciação do objeto
LiquidCrystal_I2C lcd (endereco,colunas,linhas);
//****************inclusão do arreio
byte coluna [8]={
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
};
//*****************************************************void setup**********************************************************************************
void setup(){
//****************pin mode
  pinMode(botao_joga_1, INPUT_PULLUP);
  pinMode(botao_joga_2, INPUT_PULLUP);
  pinMode(botao_finalizar, INPUT_PULLUP);
  pinMode(pin_bazzer, OUTPUT);
//****************iniciando comunicação com lcd
  lcd.init();
  lcd.backlight();
  lcd.clear();
//****************arreio  de pixels lcd
  lcd.createChar(1, coluna);
}
//*****************************************************void loop**********************************************************************************
void loop(){
//****************ao clicar no botão faz a comparação quem ganhou
   if (digitalRead(botao_finalizar)==LOW){
    if (jogador_1 > jogador_2){//se o jogador um tiver mais pontos que o jogador 2 jogador 1 ganha
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("JOGADOR 1 GANHOU");
    lcd.setCursor(3,1);
    lcd.print("PARABENS!!");
//****************música de vitória
    tone(pin_bazzer, 323, 1000); 
    delay(1000); 
    noTone(pin_bazzer);
    delay(200); 
    tone(pin_bazzer, 432, 1000); 
    delay(1000); 
    noTone(pin_bazzer);
    delay(200); 
    tone(pin_bazzer,532, 1000); 
    delay(800); 
    noTone(pin_bazzer);
    delay(200); 
    tone(pin_bazzer,532, 1000); 
    delay(800); 
    noTone(pin_bazzer);
    delay(200); 
    tone(pin_bazzer,532, 2000); 
    delay(2000); 
    noTone(pin_bazzer);
    delay(3000);
    jogador_1=0;//zera as  variáveis
    jogador_2=0;
   }
  
   if (jogador_1 < jogador_2){//se o jogador 2 tiver mais pontos que o jogador 1 jogador 2 ganha
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("JOGADOR 2 GANHOU");
    lcd.setCursor(3,1);
    lcd.print("PARABENS!!");
//****************música de vitória
    tone(pin_bazzer, 323, 1000); 
    delay(1000); 
    noTone(pin_bazzer);
    delay(200); 
    tone(pin_bazzer, 432, 1000); 
    delay(1000); 
    noTone(pin_bazzer);
    delay(200); 
    tone(pin_bazzer,532, 1000); 
    delay(800); 
    noTone(pin_bazzer);
    delay(200); 
    tone(pin_bazzer,532, 1000); 
    delay(800); 
    noTone(pin_bazzer);
    delay(200); 
    tone(pin_bazzer,532, 2000); 
    delay(2000); 
    noTone(pin_bazzer);
    delay(3000);
    jogador_1=0;//zera as  variáveis
    jogador_2=0;
   }
  }else{//se nenhum botão for apertado (botao_finalizar) coloca no placar os pontos
  lcd.setCursor(0,1);
   lcd.print("Player1");
   lcd.setCursor(3,0);
   lcd.print(jogador_1);

   lcd.setCursor(8,1);
   lcd.print("Player2");
   lcd.setCursor(11,0);
   lcd.print(jogador_2);

   lcd.setCursor(7,0);
   lcd.write(1);
   lcd.setCursor(7,1);
   lcd.write(1);

   delay(100);
   lcd.clear();

  if (digitalRead(botao_joga_1)==LOW){//se o botão for apertado adicione os pontos do jogador 1
    jogador_1++;
    delay(100);
    tone(pin_bazzer,600,100);
    delay(100);
   noTone(pin_bazzer);
  }
  if (digitalRead(botao_joga_2)==LOW){//se o botão for apertado adicione os pontos do jogador 2
    jogador_2++;
    delay(100);
    tone(pin_bazzer,500,100);
    delay(100);
   noTone(pin_bazzer);
  }
  }
}
   

  

  

