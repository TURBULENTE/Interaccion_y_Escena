void setup() {
  Serial.begin(9600);
}

void loop() {
  /*Cuando inicializamos el ciclo for
primero declaramos una variable local, 
después comprobamos una condición, 
y finalmente establecemos una instrucción
en caso de que se cumpla la condición.

Si ejecutamos este código, 
veremos en el monitor serial cómo se imprimen 
números del 0 al 9
  */
  for (int i = 0; i < 10; i++) {
    Serial.println(i);
    delay(500);
  }
}
