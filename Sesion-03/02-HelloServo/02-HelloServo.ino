// Incluimos la librería
#include <Servo.h>

// creamos un objeto servo llamado "myservo" para controlar al servo
Servo myservo;

// declaramos el número del pin para el servo
int pinServo = 9;

void setup() {
  // vinculamos al pin 9 al objeto "myservo"
  myservo.attach(pinServo);
}

void loop() {
  //Instrucción 1: ve al grado 0
  myservo.write(0);
  // Instrucción 2: espera
  delay(500);
  //Instrucción 3: ve al grado 90
  myservo.write(90);
  //Instrucción 4: espera
  delay(500);
}
