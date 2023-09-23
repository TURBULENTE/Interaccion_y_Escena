
// EJERCICIO: ORÁCULO. Por Citlali Hernández - 2023
/* Vamos a utilizar la comunicación Serial para crear un oráculo.
    Utilizaremos y manipularemos distintos tipos de datos: int, float, String
    Aplicaremos random y condicionales para definir las respuestas obtenidas.
    Customiza el oráculo añadiendo con tantos Strings y posibilidades de respuestas quieras.
    Añade secuencias de luces a modo de indicadores interactivos.
    Añade a la respuesta del oráculo dos números de la suerte: uno entero y uno con decimales
    Documenta el ejercicio en Github. Comparte nuevas ideas y reflexiones que surjan con el ejercicio. */

String s1 = "El pasado es un libro abierto, el futuro un misterio por descubrir";
String s2 = "Las respuestas están dentro de ti, solo necesitas buscarlas.";
String s3 = "La sabiduría se encuentra en la quietud del alma.";
String numero = "Tus números de la suerte son: ";
String miPregunta;
int valRandom;
int r = 5;
int v = 6;
int a = 7;
int numSuerte;
float numSuerteF;


void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  if (Serial) {                                           // Comprobamos que el Monitor Serial está abierto
    Serial.println("¡Hola humano! Hazme una pregunta.");  // Imprimimos el texto
  }
}

void loop() {

  if (Serial.available() > 0) {                 // la función serial.available lee información del puerto serial
    miPregunta = Serial.readStringUntil('\n');  // "\n" - nueva línea, "\r" - Retorno al inicio,
    Serial.print("Tu pregunta es: ");
    Serial.println(miPregunta);
    delay(2000);

    // Tiramos un "dado" para conseguir un número aleatorio entre 0 y 2.
    valRandom = random(0, 3);

    if (valRandom == 0) {
      Serial.println(s1);
      digitalWrite(r, HIGH);
      digitalWrite(v, LOW);
      digitalWrite(a, LOW);
      delay(1000);
      digitalWrite(r, LOW);
    } else if (valRandom == 1) {
      Serial.println(s2);
      digitalWrite(r, LOW);
      digitalWrite(v, HIGH);
      digitalWrite(a, LOW);
      delay(1000);
      digitalWrite(v, LOW);
    } else if (valRandom == 2) {
      Serial.println(s3);
      digitalWrite(r, LOW);
      digitalWrite(v, LOW);
      digitalWrite(a, HIGH);
      delay(1000);
      digitalWrite(a, LOW);
    }
    delay(1500);  // añadimos un poco de tiempo de espera
    // Tiramos un "dado" para conseguir un número aleatorio de la suerte en un rango entre 0 y 32.
    numSuerte = random(0, 32);
    // Tiramos un "dado" para conseguir un número aleatorio de la suerte en un rango entre 0 y 32.
    numSuerteF = random(0, 11) * 0.1;
    Serial.println(numero);
    Serial.println(numSuerte);
    Serial.println(numSuerteF);
    delay(1500);
    Serial.println(" -------- ¿Cuál es tu siguiente pregunta?.");
  }
}
