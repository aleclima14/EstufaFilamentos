#include "Arduino.h"
#include <LiquidCrystal.h>
#include "Pin_Map.h"
#include "Display.h"
#include "Temperature_Sensor.h"
#include "Menu.h"
#include "Teclado.h"


int Menu (int mudaMenu)
{

  //int *mudaMenu;
  switch (mudaMenu)
  {
    case telaInicial:
      TelaInicial ();
      break;

    case telaMenu:
      break;

    case telaAquecimento:
      TelaAquecimento ();
      break;

    case telaTemporizador:
      break;

    case telaConfiguracoes:
      break;

  }
}
