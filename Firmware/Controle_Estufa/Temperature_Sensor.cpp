/*
 * 
 */

/****INCLUDES****/
#include "Temperature_Sensor.h"
#include <DHT.h>

/****GLOBAL VARIABLES****/
int setTemperature = 0;
int targetTemp = 90;
int humidity = 58;

float TemperatureSensor;
float HumiditySensor;

DHT dht(DHT_PIN, DHT_TYPE);

/*Temperature Sensor Init with internal ADC reference (1,1 V for this MCU)*/
void InitTemperature()
{
  analogReference(INTERNAL);
  dht.begin();
}

/*Get sensor data*/
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
