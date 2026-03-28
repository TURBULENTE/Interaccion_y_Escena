/*
Controlamos la dirección de un Stepper Motor modelo 28BYJ-48 
Basado en el ejemplo de Nikodem Bartnik - nikodembartnik.pl
https://github.com/NikodemBartnik/ArduinoTutorials/tree/master/28BYJ-48
Prof. Citlali Hernández, IT 2026
En este código cambiaremos la dirección del motor con un botón.
*/

// Aquí definimos los pines a los que está conectado nuestro stepper
#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12

//Definimos una variable que luego usaremos para ir variando la rotación del motor
int step_number = 0;

int boton = 3;   // Conectamos un boton al pin 3
int valBot = 0;  // Definimos una variable que leerá el valor del botón
int velocidad = 10;
// El tiempo de espera entre cada rotación del motor. Esto se percibirá como la velocidad.
// Mientras más elevado sea el valor, más lento será el movimiento. 
// En este motor funciona bien un valor mínimo de 3

void setup() {
  pinMode(boton, INPUT);

  // Declaramos los pines del motor como outputs
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
}

void loop() {

  valBot = digitalRead(boton);

  if (valBot == 0) { // Si el botón no está presionado
    derecha(); // gira a la derecha
    delay(velocidad); 
  } else if (valBot == 1) { // si elbotón está presionado
    izquierda(); // gira a la izquierda
    delay(velocidad);
  }

  step_number++;
  if (step_number > 3) {
    step_number = 0;
  }
}


// - - - - - Mis Funciones - - - - - 


void izquierda() {
  switch (step_number) {
    case 0:
      digitalWrite(STEPPER_PIN_1, HIGH);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      break;
    case 1:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, HIGH);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      break;
    case 2:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, HIGH);
      digitalWrite(STEPPER_PIN_4, LOW);
      break;
    case 3:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, HIGH);
      break;
  }
}


void derecha() {
  switch (step_number) {
    case 0:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, HIGH);
      break;
    case 1:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, HIGH);
      digitalWrite(STEPPER_PIN_4, LOW);
      break;
    case 2:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, HIGH);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      break;
    case 3:
      digitalWrite(STEPPER_PIN_1, HIGH);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
  }
}