#include "Temperature_Sensor.h"
#include <DHT.h>

int setTemperature = 0;
int targetTemp = 90;
int humidity = 58;

float TemperatureSensor;
float HumiditySensor;

DHT dht(DHT_PIN, DHT_TIPO);

/* Inicia a leitura e referencia o ADC com a tensao interna (1,1 para o MCU usado) */
void InitTemperature()
{
  analogReference(INTERNAL);
  dht.begin();
}

/* Recebe do sensor as temperaturas lidas */
void GetTemperature()
{
  TemperatureSensor = dht.readTemperature();
  HumiditySensor = dht.readHumidity ();
}

/*
void SetTemperature ()
{
  switch (TeclaPressionada ())
  {
    case Left:
      if (setTemperature > 0)
      {
        if (setTemperature == SET_TEMPERATURE_MIN)
        {
          setTemperature = 1;
        }
        setTemperature--;
      }
      break;

    case Select:
      break;

    case Right:
      if (setTemperature < SET_TEMPERATURE_MAX)
      {
        if (setTemperature < SET_TEMPERATURE_MIN)
        {
          setTemperature = SET_TEMPERATURE_MIN - 1;
        }
        setTemperature++;
      }
      break;

    default:
      break;
  }

}*/
