/* En este código simple, entendermos el funcionamiento del comando switch.
Es una manera distinta de usar condicionales, pero en este caso ponemos instrucciones de acuerdo a "casos".
Prof. Citlali Hernández, IT 2026
*/

int caso = 0;  // Hacemos una variable con valor de cero, y que irá sumando 1 en cada vuelta del loop.

void setup() {
  Serial.begin(9600);
}

void loop() {

  switch (caso) {  // switch necesita recibir un número, aquí será "caso" que hemos inicializado previamente como cero
    case 0:        // recibimos 0, etonces...
      Serial.println("caso 0");
      break;
    case 1:  // recibimos 1, etonces...
      Serial.println("caso 1");
      break;
    case 2:  // recibimos 2, etonces...
      Serial.println("caso 2");
      break;
    case 3:  // recibimos 3, etonces...
      Serial.println("caso 3");
      break;
  }

  caso++;  // Sumamos 1 al valor de caso

  if (caso > 3) {  // si caso llega a 3, reset a 0
    caso = 0;
  }

  delay(500);  // esperamos medio segundo para poder leer tranquilamente el valor en el monitor serial
}
