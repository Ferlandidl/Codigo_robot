#include <analogWrite.h>
/* Balam 2023 */

// Define pines
// Pines de sensores QRE
#define PIN_QRE1 36
#define PIN_QRE2 39
#define PIN_QRE3 34

// Sensores de motor
const int AIN1 = 13;
const int AIN2 = 15;
const int BIN1 = 2;
const int BIN2 = 4;

// Sensores infrarrojos
#define PIN_J1 33
#define PIN_J2 25
#define PIN_J3 26

// Define retraso de tiempo entre pruebas
int tiempoPruebas = 1000;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_QRE1, INPUT);
  pinMode(PIN_QRE2, INPUT);
  pinMode(PIN_QRE3, INPUT);
  pinMode(PIN_J1, INPUT);
  pinMode(PIN_J2, INPUT);
  pinMode(PIN_J3, INPUT);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

void avanzar() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void retroceder() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void girar() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void atacar() {
  // Realizar acciones de ataque
  // ...

  // Ejemplo: Hacer que el robot avance hacia el enemigo
  avanzar();
  delay(1000);  // Avanzar durante 1 segundo

  // ...
}

void loop() {
  // Leer valores de los sensores
  int valorQRE1 = analogRead(PIN_QRE1);
  int valorQRE2 = analogRead(PIN_QRE2);
  int valorQRE3 = analogRead(PIN_QRE3);

  int datoJ1 = analogRead(PIN_J1);
  int datoJ2 = analogRead(PIN_J2);
  int datoJ3 = analogRead(PIN_J3);

  // Imprimir los valores leídos
  Serial.println("Probando Sensores Inferiores");
  Serial.print("QRE1: ");
  Serial.println(valorQRE1);
  Serial.print("QRE2: ");
  Serial.println(valorQRE2);
  Serial.print("QRE3: ");
  Serial.println(valorQRE3);

  // Imprimir los valores leídos de los sensores infrarrojos
  Serial.println("Probando Sensores Infrarrojos");
  Serial.print("J1: ");
  Serial.println(datoJ1);
  Serial.print("J2: ");
  Serial.println(datoJ2);
  Serial.print("J3: ");
  Serial.println(datoJ3);

  // Comprobar si el sensor es blanco o negro
  // Puedes ajustar estos valores según tus necesidades
  if (valorQRE1 < 500 && valorQRE2 < 500 && valorQRE3 < 500) {
    // Los sensores son negros, avanzar
    Serial.println("Avanzar");
    avanzar();
  } else {
    // Los sensores son blancos, retroceder y girar
    Serial.println("Detener, Retroceder y Girar");
    retroceder();
    delay(500);  // Retroceder durante 0.5 segundos
    girar();
    delay(1000); // Girar durante 1 segundo
  }

  // Comprobar si se detecta al enemigo utilizando los sensores infrarrojos
  int threshold = 500;
  if (datoJ1 > threshold || datoJ2 > threshold || datoJ3 > threshold) {
    // Enemigo detectado, atacar
    atacar();
  }

  delay(tiempoPruebas);
}
