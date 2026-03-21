/* Controlar la dirección de rotación de un motor DC doble eje 3-6V
utilizando el módulo Whadda WPI409  con el driver L298N
Ejercicio para la clase de Interacción y Escena 2023
Basado en el ejemplo de Whadda WPI409 
*/
const int in1 = 3;  // IN1 conectado al pin digital 13
const int in2 = 4;  // IN2 conectado al pin digital 12
const int enA= 9;

void setup() {
  pinMode(in1, OUTPUT);  //  IN1 como OUTPUT
  pinMode(in2, OUTPUT);  // IN2 como OUTPUT
  pinMode(enA, OUTPUT); // enA , OUTPUT - Velocidad (PWM)
  //Apagamos el motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
void loop() {
  adelante();
  apagar();
  atras();
  apagar();
}
//////////// Funciones de movimiento ////////////
void adelante() {
  analogWrite(enA, 255);
  digitalWrite(in1, HIGH);  // Encendemos el motor A en dirección 1 (Adelante)
  digitalWrite(in2, LOW);   // Apagamos el motor A en dirección 1
  delay(1000);
}
void atras() {
  analogWrite(enA, 255);
  digitalWrite(in1, LOW);   // Encendemos el motor A en dirección 2 (Atrás)
  digitalWrite(in2, HIGH);  // Apagamos el motor A en dirección 2
  delay(1000);
}
void apagar(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);
}



