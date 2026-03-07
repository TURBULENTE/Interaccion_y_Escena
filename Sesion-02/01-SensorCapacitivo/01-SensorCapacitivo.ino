/*
 * Capacitive Sensor Library Demo Sketch
 * Basado en el ejemplo y repositorio de Paul Badger 2008, y el Bare Conductive Capacitive Proximity Sensor.
 * Adaptado por Citlali Hernández.
 * Instalar librería, mediante el Library Manager.
 * Utiliza una resistencia de 10Mohms entre dos pines (uno envía y otro recibe)
 * La resistencia afecta la sensibiildad, experimentar con valores como: 50K - 50M.
 * Una resistencia con valores más alta, es necesaria para grandes sensores.
 * El "pin que recibe" es el pin del sensor. 
 */


// capacitive sensing includes
#include <CapacitiveSensor.h>

// capacitive sensing constant
CapacitiveSensor sensor = CapacitiveSensor(4, 2);  // 1M resistor between pins 4 & 2, pin 2 is sensor pin

void setup() {
  Serial.begin(115200);
}

void loop() {
  long measurement = sensor.capacitiveSensor(30);

  Serial.println(measurement);
  delay(10);
}
