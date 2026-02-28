
/*Ejemplo para leer un sensor capacitivo DIY y encender un led
Basado en el ejemplo de la librería CapacitiveSensor de Paul Badger.
Necesitaremos: 
1 material conductivo conectado a pin 2
1 resistencia 1 MOHM entre pin 2 y 4
1 led + respectiva resistencia
*/
// capacitive sensing includes
#include <CapacitiveSensor.h>
// capacitive sensing constant
CapacitiveSensor sensor = CapacitiveSensor(4,2);  // 1M resistor between pins 4 & 2, pin 2 is sensor pin

int ledV=7;

void setup() {
  Serial.begin(115200);
}

void loop() {
  long measurement =  sensor.capacitiveSensor(30);
  if(measurement>1000){
    digitalWrite(ledV, HIGH);
  }else{
    digitalWrite(ledV, LOW);
  }

  Serial.println(measurement);
  delay(10);
}

