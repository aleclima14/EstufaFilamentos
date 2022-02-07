#ifndef Teclado_h
#define Teclado_h

#include "Arduino.h"
#include "Display.h"

void IniciaTeclado ();
int TeclaPressionada ();
void LeTeclado();

enum Tecla
{
  Left   = 0x01, 
  Select = 0x02,
  Right  = 0x03
};


#endif
