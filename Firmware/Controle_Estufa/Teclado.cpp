/*
 * 
 */

/****INCLUDES****/
#include "Arduino.h"
#include "Teclado.h"
#include "Pin_Map.h"
#include "Config.h"

/****GLOBAL VARIABLES****/
uint8_t botaoLeft   = 0;
uint8_t botaoSelect = 0;
uint8_t botaoRight  = 0;

uint8_t flagLeft    = 0;
uint8_t flagSelect  = 0;
uint8_t flagRight   = 0;

unsigned long debounceLeft    = 0;
unsigned long debounceSelect  = 0;
unsigned long debounceRight   = 0;


/*Keypad Init*/
void IniciaTeclado ()
{
  pinMode (LEFT_PIN, INPUT_PULLUP);
  pinMode (SELECT_PIN, INPUT_PULLUP);
  pinMode (RIGHT_PIN, INPUT_PULLUP);
}

/*Key Pressed Function*/
int TeclaPressionada ()
{
  //Read pins
  botaoLeft   = digitalRead (LEFT_PIN);
  botaoRight  = digitalRead (RIGHT_PIN);
  botaoSelect = digitalRead (SELECT_PIN);

  //Left Button
  if (!botaoLeft)
  {
    if ((millis() - debounceLeft) > DEBOUNCE)
    {
      debounceLeft = millis();
      flagLeft = 0x01;
      if (!botaoLeft && (flagLeft == 0x01))
      {
        flagLeft = 0x00;
        return Left;
      }
    }
  }
  
  //Right Button
  if (!botaoRight)
  {
    if ((millis() - debounceRight) > DEBOUNCE)
    {
      debounceRight = millis();
      flagRight = 0x01;
      if (!botaoRight && (flagRight == 0x01))
      {
        flagRight = 0x00;
        return Right;
      }
    }
  }

  //Select Button
  if (!botaoSelect)
  {
    if ((millis() - debounceSelect) > 300)
    {
      debounceSelect = millis();
      flagSelect = 0x01;
      if (!botaoSelect && (flagSelect == 0x01))
      {
        flagSelect = 0x00;
        return Select;
      }
    }
  }

  return 0x00;
}
