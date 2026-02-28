//Aleatoreidad y Pseudorandom
// Interacción y Escena - IT - Citlali Hernández 2023
/* Los números que nos devuelve la función "random()" en realidad
responden a un algoritmo que genera una misma secuencia de números desordenados.
Para poder cambiar la posición en la lista de números, podemos utilizar la función randomSeed();
El problema de esto, es que aunque cambiemos esta semilla, volveremos a tener una lista con los mismos números.
Un truco comunmente utilizado para resolver este problema, es utilizar el valor derivado de la lectura de un pin analógico
como semilla en el randomSeed(); cada vez que iniciemos nuestro programa. 
Aquí un ejemplo.
*/

int numRandom_A;  // declaramos una variable para almacenar el número aleatorio
int analogPin; // variable para almacenar el valor del pin analógico

void setup() {
  Serial.begin(9600);
  analogPin = analogRead(A0); // leemos el pin analógico
  randomSeed(analogPin); // asignamos el valor del pin analógico al seed
}

void loop() {

  numRandom_A = random(13);
  Serial.print("Número Aleatorio= ");
  Serial.println(numRandom_A);
  delay(500);
}
