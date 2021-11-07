#include "Temperature_Sensor.h"



int setTemperatura = 0;
int alvo = 90;
int umidade = 58;

void SetTemperatura ()
{
  switch (TeclaPressionada ())
  {
    case Left:
      if (setTemperatura > 0)
      {
        if (setTemperatura == SET_TEMPERATURA_MIN)
        {
          setTemperatura = 1;
        }
        setTemperatura--;
      }
      break;

    case Select:
      break;

    case Right:
      if (setTemperatura < SET_TEMPERATURA_MAX)
      {
        if (setTemperatura < SET_TEMPERATURA_MIN)
        {
          setTemperatura = SET_TEMPERATURA_MIN - 1;
        }
        setTemperatura++;
      }
      break;

    default:
      break;
  }

}
