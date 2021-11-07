/*
   Codigo criado por Alecsander 02/10/2021
   Todos os direitos reservados
*/

#include "Display.h"
#include "Teclado.h"
#include "Menu.h"

unsigned long timer = 0;

void setup()
{
  //Serial.begin (9600);
  IniciaTeclado ();

  IniciaDisplay ();

  Menu (telaInicial);
  //Menu (telaAquecimento);

}

void loop()
{
  //SelectIcone(3);
  if (millis() - timer > 100)
  {
    if (TeclaPressionada() == Select)
    {
      Menu (telaAquecimento);
    }
    timer = millis();
  }
}
