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

/* Teclado direcional */
#define LEFT_PIN    6
#define SELECT_PIN  7
#define RIGHT_PIN   8
//#define RETURN_PIN 

/* DHT sensor de temperatura */
#define DHT_PIN 10

/* Controle de aquecimento */
#define CONTROL_PIN 9

/* Aviso sonoro */
//#define BUZZER_PIN 11