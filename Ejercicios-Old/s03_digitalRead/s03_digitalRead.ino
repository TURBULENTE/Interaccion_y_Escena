/* Ejercicio para hacer lectura de un Soft Button 
utilizando digitalRead();
*/

int valSensor; // declaramos una variable que almacenará la lectura del sensor
const int led0=5 ; // declaramos una constante para el número de pin de nuestro sensor

void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT); // Si no conectamos una resistencia y hacemos el circuito utilizando la resistencia interna de Arduino, entonces necesitaremos colocar: INPUT_PULLUP 
  pinMode(led0, OUTPUT);
}

void loop() {
  valSensor = digitalRead(8);
  Serial.println(valSensor);
  if(valSensor== HIGH){
digitalWrite(led0,  LOW);
  }else{
digitalWrite(led0, HIGH);
  }
}
