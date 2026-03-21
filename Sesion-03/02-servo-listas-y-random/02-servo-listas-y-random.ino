#include <Servo.h>
Servo myservo;
int pinSer = 3;

// Creamos una lista de valores
int miLista[] = { 2, 15, 30, 180, 7 };

// Creamos una variable llamada dado
// que en el loop almacernará números aleatorios
int dado;

void setup() {
  myservo.attach(pinSer);
  Serial.begin(9600);
}

void loop() {
  comportamiento1();
}

//Creamos una función con un comportamiento de movimiento
void comportamiento1() {
  //Instrucción 1: dame un número aleatorio
  // random(5) me dará un número entre 0 y 4
  dado = random(5);

  // Instrucción 2: imprime el valor de dado
  Serial.println(dado);

  // Instrucción 3: mover el motor a un valor aleatorio de la lista
  myservo.write(miLista[dado]);

  // Instrucción 4: espera
  delay(1000);
}
