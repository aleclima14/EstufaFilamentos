#include "Arduino.h"

/**
 * TODO: modificar na placa o pino en do LCD para o pino 13 e adicionar o buzzer no pino 11.
 * 
 * Encontrar um pino adequado para o botao referente ao RETURN_PIN
 * 
 */

/* LCD 1602 ou 1604 */
#define rs 12
#define en 11
//#define en 13
#define d4 5
#define d5 4
#define d6 3
#define d7 2 

/*Navigation Keypad*/
#define LEFT_PIN    6
#define SELECT_PIN  7
#define RIGHT_PIN   8

/* DHT Temperature Sensor*/
#define DHT_PIN 10

/*Heating Control Pin */
#define CONTROL_PIN 9

/*Warning Chirp*/
//#define BUZZER_PIN 11
