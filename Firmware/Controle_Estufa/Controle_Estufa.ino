/*
   Codigo criado por Alecsander 02/10/2021
   Todos os direitos reservados
*/

#include "Display.h"
#include "Teclado.h"
#include "Menu.h"

unsigned long timer = 0;
extern void (*NavegaTela)();

void setup()
{
  IniciaTeclado ();

  IniciaDisplay ();

  IniciaLeituraTemperatura();
}

void loop()
{
  GetTemperatura();
  (*NavegaTela)();
}
