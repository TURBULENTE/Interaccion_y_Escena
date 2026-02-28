////////// VARIABLES Y CONSTANTES //////////
int numRandom;
const int led0 = 9;
String miPregunta;
String t0 = "Tu futuro es impredecible, pero parece feliz.";
String t1 = "Tu futuro pinta mal.";

//////////// MI SETUP /////////////
void setup() {

  Serial.begin(9600);
  pinMode(led0, OUTPUT);
  if (Serial) {
    Serial.println("Hazme una pregunta.");
  }
}


//////////// MI LOOP /////////////
void loop() {

  if (Serial.available() > 0) {

    miPregunta = Serial.readStringUntil('\n');  // '\n' - nueva línea,  '\r' Retorno al inicio,  't\' Tabulador
    Serial.println(miPregunta);
    delay(1000);
    numRandom = random(0, 2);

    if (numRandom == 0) {
      Serial.println(t0);
      delay(250);
      digitalWrite(led0, HIGH);
      delay(500);
      digitalWrite(led0, LOW);
      delay(500);
    }

    if (numRandom == 1) {
      Serial.println(t1);
      delay(250);
    }
  }
}
