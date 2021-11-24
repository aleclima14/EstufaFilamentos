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

  IniciaLeituraTemperatura();

  Menu (telaInicial);
  //Menu (telaAquecimento);

}

void loop()
{
  GetTemperatura();
  Menu (telaInicial);
  
  //SelectIcone(3);
  
  /*
  if (millis() - timer > 100)
  {
    if (TeclaPressionada() == Select)
    {
      Menu (telaAquecimento);
    }
    timer = millis();
  }
  */
}
