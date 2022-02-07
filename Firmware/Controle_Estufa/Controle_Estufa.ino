/*
 *    Codigo criado por Alecsander 02/10/2021
      Todos os direitos reservados
 */

/****INCLUDES****/
#include "Display.h"
#include "Teclado.h"
#include "Temperature_Sensor.h"

/****GLOBAL VARIABLES****/
unsigned long timer = 0;
extern void (*NavegaTela)();
//uint8_t keyPressed;

/****MAIN FUNCTION****/
void setup()
{
  IniciaTeclado ();
  IniciaDisplay ();
  InitTemperature();

  Serial.begin(9600);
  
}
/****LOOP FUNCTION****/
void loop()
{
  GetTemperature();
  (*NavegaTela)();
}
