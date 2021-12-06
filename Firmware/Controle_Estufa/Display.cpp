#include "Display.h"
#include "Temperature_Sensor.h"
#include "Teclado.h"
#include "Menu.h"

LiquidCrystal lcd (rs, en, d4, d5, d6, d7);


extern int setTemperatura;
extern int alvo;
extern int umidade;

extern float TempSensor;
extern float UmidSensor;

int iconePosicao = 0;
unsigned long timer1 = 0;

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

/*
  Funcao responsavel por mostrar o icone ">" na primeira coluna do display
  Recebe como referencia a quantidade de opcoes no menu
  Por exemplo
  >Aquecer
   Desligar
  Aqui temos 3 menus, entao basta usar SelectIcone (3).
*/
int SelectIcone(int maxMenu)
{
  if (iconePosicao == 0)
  {
    lcd.setCursor (0, 0);
    lcd.print (">");
  }

  switch (TeclaPressionada())
  {
    case Left:
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

      return iconePosicao;
      break;

    case Right:
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

      return iconePosicao;
      break;

    default:
      break;
  }
}

void TelaInicial ()
{
  lcd.setCursor (0, 0);
  lcd.print (String ("Temp.: ") + String (TempSensor, 0) + String (" / ") + String (setTemperatura) + char (223) + String ("C  ") );

  lcd.setCursor (0, 1);
  lcd.print (String ("Umidade: ")  + String (UmidSensor, 0) + String ("%"));

  if (TeclaPressionada() == Select)
  {
    LimpaTela();
    NavegaTela = TelaAquecimento;
  }
}

void TelaAquecimento ()
{
  if (millis() - timer1 > 10 )
  {
    /*Informa a funcao a quantidade de linhas o menu tem (no caso 2)*/
    SelectIcone(2);

    lcd.setCursor (1, 0);
    lcd.print ("Aquecer");

    lcd.setCursor (1, 1);
    lcd.print ("Desligar");

    if (TeclaPressionada() == Select && iconePosicao == 1)
    {
      iconePosicao = 0;
      LimpaTela();
      NavegaTela = TelaInicial;
    }

    timer1 = millis();
  }
}
