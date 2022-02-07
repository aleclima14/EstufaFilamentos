/*
   Codigo criado por Alecsander 02/10/2021
   Todos os direitos reservados
*/

#include "Display.h"
#include "Teclado.h"
#include "Temperature_Sensor.h"

unsigned long timer = 0;
extern void (*NavegaTela)();

uint8_t keyPressed;
void setup()
{
  IniciaTeclado ();
  IniciaDisplay ();
  InitTemperature();

}

void loop()
{
  GetTemperature();
  (*NavegaTela)();
}
