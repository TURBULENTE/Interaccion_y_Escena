// EJERCICIO: ORÁCULO. Por Citlali Hernández - 2023
/* Vamos a utilizar la comunicación Serial para crear un oráculo.
    Utilizaremos y manipularemos distintos tipos de datos: int, float, String
    Aplicaremos random y condicionales definir las respuestas obtenidas.
    Customiza el oráculo añadiendo Strings compuestos y amplando las posibilidades.
    Añade secuencias de luces a modo de indicadores interactivos.
    Añade a la respuesta del oráculo dos números de la suerte: uno entero y uno
    Documenta el ejercicio en Github. Comparte nuevas ideas y reflexiones que surjan con el ejercicio. */

String s1 = "El pasado es un libro abierto, el futuro un misterio por descubrir";
String s2 = "Las respuestas están dentro de ti, solo necesitas buscarlas.";
String s3 = "La sabiduría se encuentra en la quietud del alma.";
String numero = "Tu número de la suerte es: ";
String miPregunta;
int valRandom;
int r = 5;
int v = 6;
int a = 7;
int numSuerte;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  if(Serial){
  Serial.println("Hazme una pregunta.");
}
}

void loop() {

  if (Serial.available() > 0) { // la función serial.available lee información del puerto serial
    miPregunta = Serial.readStringUntil('\n');
    Serial.print("Tu pregunta es: ");
    Serial.println(miPregunta);
    delay(500);

    valRandom = random(0, 3);
    numSuerte = random(0, 30);

    if (valRandom == 0) {
      Serial.println(s1);
      Serial.println(numero + numSuerte);
      digitalWrite(r, HIGH);
      digitalWrite(v, LOW);
      digitalWrite(a, LOW);
      delay(1000);
      digitalWrite(r, LOW);
    }

    if (valRandom == 1) {
      Serial.println(s2);
      Serial.println(numero + numSuerte);
      digitalWrite(r, LOW);
      digitalWrite(v, HIGH);
      digitalWrite(a, LOW);
      delay(1000);
      digitalWrite(v, LOW);
    }

    if (valRandom == 2) {
      Serial.println(s3);
      Serial.println(numero + numSuerte);
      digitalWrite(r, LOW);
      digitalWrite(v, LOW);
      digitalWrite(a, HIGH);
      delay(1000);
      digitalWrite(a, LOW);
    }
  }
}
