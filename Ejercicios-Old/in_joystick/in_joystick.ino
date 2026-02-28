/*Lectura del Joystick sin librerías
Interacción y Escena - 2023 - Citlali Hernández
*/
int sensorPinx = A6;   
int sensorPiny = A7; 
int sensorPinz = 2; 

int x, y, z;

void setup() {
  pinMode(sensorPinx, INPUT);
  pinMode(sensorPiny, INPUT);
  pinMode(sensorPinz, INPUT);
  Serial.begin(9600);
}

void loop() {
 x=analogRead(sensorPinx);
 y=analogRead(sensorPiny);
 z=digitalRead(sensorPinz);
 Serial.print("X= ");
 Serial.println(x);
 Serial.print("Y= ");
 Serial.println(y);
 Serial.print("Z= ");
 Serial.println(z);

 delay(350);
}
