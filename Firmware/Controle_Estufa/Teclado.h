#ifndef Teclado_h
#define Teclado_h

#include "Arduino.h"
#include "Display.h"

void IniciaTeclado ();
int TeclaPressionada ();

enum Teclas
{
  Left, 
  Select,
  Right,
  nulo
};


#endif
