// DC Motor Keyestudio
// Ejercicio de clase - Interacción y Escena 2023 - Citlali Hernández

// Declaramos las dos constantes con los pines digitales del motor
// En el caso de la placa de Keyestudio, ambos pines están en un mismo conector RJ11
const int in1 = 4;
const int in2 = 3;


void setup() {
  // Establecemos ambos pines como OUTPUTS
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Apagamos al motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop() {

  derecha();
  apagar();
  izquierda();
  apagar(); 
}

// Esta función agrupa el código que mueve
void derecha() {
  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(1000);
}

void izquierda() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(1000);
}

void apagar() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(2000);
}
