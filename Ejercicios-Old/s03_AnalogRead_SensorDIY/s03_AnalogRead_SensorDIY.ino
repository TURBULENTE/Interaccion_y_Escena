/* Leer un sensor de presión DIY y hacer un mapeo de sus valores a un led.
 Código basado en el ejemplo "AnalogInSerialOut"
 Interacción y Escena - 2023 - Citlali Hernández
 Ejercicio basado en el ejemplo "AnalogInOutSerial"
 */


const int analogInPin = A0;  // Pin analógico de entrada para el sensor
const int analogOutPin = 9;  // PIn analógico de salida para el led (PWM)

int valSensor = 0;  // variable para almacenar el valor del sensor
int valLed = 0;     // variable para almacenar y enviar valores por PWM al led

void setup() {
  Serial.begin(9600);  // Inicializamos la comunicación Serial
}

void loop() {
  valSensor = analogRead(analogInPin);       // leemos el sensor
  valLed = map(valSensor, 0, 1023, 0, 255);  // hacemos un mapeo de valores para el led. ¿Qué rango os da vuestro sensor?
  analogWrite(analogOutPin, valLed);         // Enviamos los valores mapeados al led.

  // Imprimimos los valores del sensor
  Serial.print("sensor = ");
  Serial.print(valSensor);
  Serial.print("\t output = ");  // Usamos tabulador para dar un espacio entre los textos
  Serial.println(valLed);        // Imprimimos el valor del la variable valLed

  delay(100);  //Esperamos antes de comenzar el bucle
}
