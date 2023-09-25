/****
Ejercicio: Fade in, fade out. Prof. Citlali Hernández 2023.
Vamos a controlar el brillo de un led utilizando analogWrite();.
Podemos enviar valores en un rango de 0-255
Utilizaremos variables para modificar el valor por cada ciclo de nuestro bucle
Veréis que en este ejercicio hemos añadido a un 2ndo led que tiene el comportamiento inverso. 
***/

int ledVerde = 9;
int ledRojo = 6;
int fadeCount = 1;  // El valor del incremento del brillo por cada bucle (podéis experimentar incrementando este valor)
int brillo0 = 0;    // Valor inicial del brillo para un led.
int brillo1 = 255;  // Valor inicial del brillo para un 2ndo led.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledRojo, OUTPUT);
  analogWrite(ledRojo, LOW);
}

void loop() {


  brillo0 = brillo0 + fadeCount;
  brillo1 = brillo1 - fadeCount;

  // La siguiente operación es un codicional que comprueba si unas condiciones se cumplen.
  // Si el brillo es menor o igual a 0 , ó el brillo es mayor o igual que 255. Entonces haz unas instrucciones.
  if (brillo0 <= 0 || brillo0 >= 255) {  //Añadimos el operador lógico "||" que significa "Or".
    fadeCount = -fadeCount;              // Silas condiciones se cumplen, convierte el vlor de fadeCount a negativo.
  }

  // Para corroborar qué valor del brillo tenemos ,imprimimos la siguiente información:
  Serial.print("brillo 0 = ");
  Serial.println(brillo0);
  Serial.print("brillo 1 = ");
  Serial.println(brillo1);
  analogWrite(ledRojo, brillo0);
  analogWrite(ledVerde, brillo1);
  delay(10);
}
