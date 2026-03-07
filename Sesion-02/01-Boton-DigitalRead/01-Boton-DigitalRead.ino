
int valorBoton;  // Declaro una variable que almacenará el valor de mi botón

void setup() {
  pinMode(2, INPUT);   // Presentamos al pin 2 como INPUT
  Serial.begin(9600);  // Comenzamos la comunicación serial
}

void loop() {
  valorBoton = digitalRead(2); // leemos el valor del pin y lo almacenamos en la variable
  Serial.println(valorBoton); // imprimimos el valor en el monitor Serial (deberá de ser 1, ò 0)
}
