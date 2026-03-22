/*
Controlar un motor DC doble eje 3-6V
utilizando el módulo Whadda WPI409 con el driver L298N
Ejercicio para la clase de Interacción y Escena 2023, Citlali Hernández
Basado en el tutorial de Last Minute Engineers https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/
*/


const int enA = 9;  // Añadimos un pin PWM para controlar la velocidad
const int in1 = 13;
const int in2 = 12;


void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Apagamos el motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop() {
  aceleracion();
  delay(1000);
}

///Funcion de movimiento: cambiamos la velocidad en una dirección ///


// Con esta función aceleramos y desaceleramos al motor
void aceleracion() {

  // Encendemos el motores en una dirección
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);


  //Aceleración
  // Utilizamos un bucle for para aumentar la velocidad de manera gradual
  for (int i = 0; i < 256; i++) {
    analogWrite(enA, i);  // enviamos una señal analógica (0-255) al pin 9(enA)
    delay(20);
  }

  //Desaceleración
  // Utilziamos un bucle for para desacelerar e ir de 255 a 0.
  for (int i = 255; i >= 0; --i) {
    analogWrite(enA, i);  // enviamos una señal analógica (0-255) al pin 9(enA)
    delay(20);
  }

  // Apagamos el motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}