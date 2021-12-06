#include "Temperature_Sensor.h"
#include <DHT.h>

int setTemperatura = 0;
int alvo = 90;
int umidade = 58;

float TempSensor;
float UmidSensor;

DHT dht(DHT_PIN, DHT_TIPO);

/* Inicia a leitura e referencia o ADC com a tensao interna (1,1 para o MCU usado) */
void IniciaLeituraTemperatura()
{
  analogReference(INTERNAL);
  dht.begin();
}

/* Recebe do sensor as temperaturas lidas */
void GetTemperatura()
{
  TempSensor = dht.readTemperature();
  UmidSensor = dht.readHumidity ();
}

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
