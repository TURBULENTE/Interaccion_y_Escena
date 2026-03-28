/*
Controlamos la dirección de un Stepper Motor modelo 28BYJ-48 
Basado en el ejemplo de Nikodem Bartnik - nikodembartnik.pl
https://github.com/NikodemBartnik/ArduinoTutorials/tree/master/28BYJ-48
Prof. Citlali Hernández, IT 2026
*/

// Aquí definimos los pines digitales a los que está conectado nuestro stepper
#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12

//Definimos una variable que luego usaremos para ir variando la rotación del motor
int step_number = 0;

int velocidad = 3;
// El tiempo de espera entre cada rotación del motor. Esto se percibirá como la velocidad.
// Mientras más elevado sea el valor, más lento será el movimiento.
// En este motor funciona bien un valor mínimo de 3

void setup() {


  // Declaramos los pines del motor como outputs
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
}

void loop() {

  for (int i = 0; i < 2048; i++) { // Una vuelta completa de nuestro stepper son 2048 pasos
    izquierda();
    delay(velocidad);

    step_number++;
    if (step_number > 3) {
      step_number = 0;
    }
  }
  delay(1000);
}

// - - - - - Mis Funciones - - - - -

void izquierda() {

  // Hacemos uso de la función switch case, para ir rotando nuestro motor por pasos
  // De acuerdo al orden en que activamos los campos magnéticos.
  //Video explicativo: https://www.youtube.com/watch?v=7spK_BkMJys&time_continue=29&source_ve_path=NzY3NTg&embeds_referring_euri=https%3A%2F%2Fhowtomechatronics.com%2F&embeds_referring_origin=https%3A%2F%2Fhowtomechatronics.com
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