#include "Display.h"
#include "Temperature_Sensor.h"
#include "Teclado.h"

LiquidCrystal lcd (rs, en, d4, d5, d6, d7);


extern int setTemperature;
extern int targetTemp;
extern int humidity;

extern float TemperatureSensor;
extern float HumiditySensor;

uint8_t iconePosicao = 0;
unsigned long timer1 = 0;
unsigned long timer2 = 0;

void (*NavegaTela)();

void IniciaDisplay ()
{
  lcd.begin (16, 4);
  NavegaTela = TelaInicial;
}

void LimpaTela()
{
  lcd.clear();
}

void TelaInicial ()
{
  lcd.setCursor (0, 0);
  lcd.print (String ("Temp.: ") + String (TemperatureSensor, 0) + String (" / ") + String (setTemperature) + char (223) + String ("C  ") );

  lcd.setCursor (0, 1);
  lcd.print (String ("Umidade: ")  + String (HumiditySensor, 0) + String ("%"));

  if (TeclaPressionada() == Select)
  {
    LimpaTela();
    NavegaTela = TelaAquecimento;
  }
}

void TelaAquecimento ()
{
  uint8_t key;
  uint8_t maxMenu = 3; /*Informa a funcao a quantidade de linhas o menu tem (no caso 3)*/
  key = TeclaPressionada();

  if (iconePosicao == 0)
  {
    lcd.setCursor (0, 0);
    lcd.print (">");
  }

  if (key == Left)
  {
    if (iconePosicao > 0)
    {
      iconePosicao --;
    }
    //Apaga a seta na primeira posicao
    lcd.setCursor (0, iconePosicao + 1);
    lcd.print (" ");

    //Mostra a seta conforme a posicao definida
    lcd.setCursor (0, iconePosicao);
    lcd.print (">");
  }

  if (key == Right)
  {
    if (iconePosicao < maxMenu - 1)
    {
      iconePosicao ++;
    }
    //Apaga a seta na primeira posicao
    lcd.setCursor (0, iconePosicao - 1);
    lcd.print (" ");

    //Mostra a seta conforme a posicao definida
    lcd.setCursor (0, iconePosicao);
    lcd.print (">");
  }

  lcd.setCursor (1, 0);
  lcd.print ("Voltar");

  lcd.setCursor (1, 1);
  lcd.print ("Aquecer");

  lcd.setCursor (1, 2);
  lcd.print ("Desligar");

  //Voltar
  if (key == Select && iconePosicao == 0)
  {
    iconePosicao = 0;
    LimpaTela();
    NavegaTela = TelaInicial;
  }
  //Aquecer
  if (key == Select && iconePosicao == 1)
  {
    iconePosicao = 0;
    LimpaTela();
    NavegaTela = TelaAquecer;
  }

  //Desligar
  if (key == Select && iconePosicao == 2)
  {
    iconePosicao = 0;
    LimpaTela();
    setTemperature = 0;
    NavegaTela = TelaInicial;
  }
}


void TelaAquecer ()
{
  uint8_t key;
  uint8_t maxMenu = 4; /*Informa a funcao a quantidade de linhas o menu tem (no caso 4)*/
  key = TeclaPressionada();

  if (iconePosicao == 0)
  {
    lcd.setCursor (0, 0);
    lcd.print (">");
  }

  if (key == Left)
  {
    if (iconePosicao > 0)
    {
      iconePosicao --;
    }
    //Apaga a seta na primeira posicao
    lcd.setCursor (0, iconePosicao + 1);
    lcd.print (" ");

    //Mostra a seta conforme a posicao definida
    lcd.setCursor (0, iconePosicao);
    lcd.print (">");
  }

  if (key == Right)
  {
    if (iconePosicao < maxMenu - 1)
    {
      iconePosicao ++;
    }
    //Apaga a seta na primeira posicao
    lcd.setCursor (0, iconePosicao - 1);
    lcd.print (" ");

    //Mostra a seta conforme a posicao definida
    lcd.setCursor (0, iconePosicao);
    lcd.print (">");
  }

  lcd.setCursor (1, 0);
  lcd.print ("Voltar");

  lcd.setCursor (1, 1);
  lcd.print ("ABS");

  lcd.setCursor (1, 2);
  lcd.print ("PLA");

  lcd.setCursor (1, 3);
  lcd.print ("PETG");

  //Voltar
  if (key == Select && iconePosicao == 0)
  {
    iconePosicao = 0;
    LimpaTela();
    NavegaTela = TelaAquecimento;
  }

  //ABS
  if (key == Select && iconePosicao == 1)
  {
    iconePosicao = 0;
    LimpaTela();
    setTemperature = 80;
    NavegaTela = TelaInicial;
  }

  //PLA
  if (key == Select && iconePosicao == 2)
  {
    iconePosicao = 0;
    LimpaTela();
    setTemperature = 50;
    NavegaTela = TelaInicial;
  }

  //PETG
  if (key == Select && iconePosicao == 3)
  {
    iconePosicao = 0;
    LimpaTela();
    setTemperature = 65;
    NavegaTela = TelaInicial;
  }

  /*TODO: Para a tela de custom, criar uma copia da tela inicial para poder modificar o valor do setTemperature,
  quando definir valor, pressionar Select e mudar para a tela inicial.*/
}
