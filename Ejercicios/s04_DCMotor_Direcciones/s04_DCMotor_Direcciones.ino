/* Controlar la dirección de rotación de un motor DC doble eje 3-6V
utilizando el módulo Whadda WPI409  con el driver L298N
Ejercicio para la clase de Interacción y Escena 2023
Basado en el ejemplo de Whadda WPI409 
*/

const int in1 = 13;  // IN1 conectado al pin digital 13
const int in2 = 12;  // IN2 conectado al pin digital 12

void setup() {
  pinMode(in1, OUTPUT);  //  IN1 como OUTPUT
  pinMode(in2, OUTPUT);  // IN2 como OUTPUT

  //Apagamos el motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop() {
  adelante();
  atras();
}

////////////////////////////////////////////////
//////////// Funciones de movimiento ////////////
void adelante() {

  digitalWrite(in1, HIGH);  // Encendemos el motor A en dirección 1 (Derecha)
  digitalWrite(in2, LOW);   // Apagamos el motor A en dirección 1 (Derecha)
  delay(1000);
}

void atras() {

  digitalWrite(in1, LOW);   // Encendemos el motor A en dirección 1 (Derecha)
  digitalWrite(in2, HIGH);  // Apagamos el motor A en dirección 1 (Derecha)
  delay(1000);
}
