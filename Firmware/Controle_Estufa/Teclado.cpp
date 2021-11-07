#include "Arduino.h"
#include "Teclado.h"
#include "Pin_Map.h"
#include "Config.h"
#include "Menu.h"

int botaoLeft = 0;
int botaoSelect = 0;
int botaoRight = 0;

int flagLeft = 0;
int flagSelect = 0;
int flagRight = 0;

unsigned long debounceGeral = 0;
unsigned long debounceLeft = 0;
unsigned long debounceSelect = 0;
unsigned long debounceRight = 0;

void IniciaTeclado ()
{
  pinMode (LEFT_PIN, INPUT_PULLUP);
  pinMode (SELECT_PIN, INPUT_PULLUP);
  pinMode (RIGHT_PIN, INPUT_PULLUP);
}

int TeclaPressionada ()
{
  //Botao LEFT
  if ((millis() - debounceLeft) > DEBOUNCE)
  {
    botaoLeft = digitalRead (LEFT_PIN);
    if (botaoLeft == LOW)
    {
      if (flagLeft == 0)
      {
        flagLeft = 1;
        return Left;
      }
      else
      {
        flagLeft = 0;
      }
    }
    debounceLeft = millis();
  }

  //Botao Right
  if ((millis() - debounceRight) > DEBOUNCE)
  {
    botaoRight = digitalRead (RIGHT_PIN);
    if (botaoRight == LOW)
    {
      if (flagRight == 0)
      {
        flagRight = 1;
        return Right;
      }
      else
      {
        flagRight = 0;
      }
    }
    debounceRight = millis();
  }


  //Botao SELECT
  botaoSelect = digitalRead (SELECT_PIN);
  if (botaoSelect == LOW && flagSelect == 0)
  {
    if ((millis() - debounceSelect) > 250)
    {
      flagSelect = 1;
      debounceSelect = millis();
      return Select;
    }
  }
  else
  {
    flagSelect = 0;
  }

  return nulo;
}


/*
  int TeclaPressionada ()
  {
  if ((millis() - debounceGeral) > 50)
  {
    //Botao LEFT
    botaoLeft = digitalRead (LEFT_PIN);
    if (botaoLeft == LOW && !botaoLeft)
    {
      if ((millis() - debounceLeft) > DEBOUNCE)
      {
        debounceLeft = millis();
        flagLeft = 0;
        return Left;
      }
    }

    //Botao SELECT
    botaoSelect = digitalRead (SELECT_PIN);
    if (botaoSelect == LOW && !botaoSelect)
    {
      if ((millis() - debounceSelect) > DEBOUNCE)
      {
        debounceSelect = millis();
        flagSelect = 0;
        return Select;
      }
    }

    //Botao RIGHT
    botaoRight = digitalRead (RIGHT_PIN);
    if (botaoRight == LOW && !botaoRight)
    {
      if ((millis() - debounceRight) > DEBOUNCE)
      {
        debounceRight = millis();
        flagRight = 0;
        return Right;
      }
    }
    return nulo;
  }
  }

*/
