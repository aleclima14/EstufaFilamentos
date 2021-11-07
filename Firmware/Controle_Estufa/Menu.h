#ifndef Menu_h
#define Menu_h


#include "Arduino.h"
#include <LiquidCrystal.h>
#include "Pin_Map.h"
#include "Display.h"
#include "Temperature_Sensor.h"
#include "Teclado.h"


enum TelaMenu
{
  telaInicial,
  telaMenu,
  telaAquecimento,
  telaTemporizador,
  telaConfiguracoes
};

int Menu (int mudaMenu); 

#endif
