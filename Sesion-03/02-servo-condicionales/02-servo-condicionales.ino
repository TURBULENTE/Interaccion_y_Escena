#include <Servo.h>
Servo myservo;
int pinSer=3; // El pin en donde está nuestro servo
int pos=0; // declaramos una variable para las posiciones del servo
int inc=1; // declaramos una variable con el número de grado que queremos que incremente 
void setup() {
myservo.attach(pinSer);
myservo.write(0);
Serial.begin(9600);
}
void loop() {

// Instrucción 1: que el servo se coloque en posición
myservo.write(pos); 

// Insturcción 2: esperar
delay(100);

//Instrucción 3: añade a la posición 1 grado
pos=pos+inc;

// Instrucción 4: Condicional
//Si la posición es mayor o igual a 180, o, menor o igual a 0 entonces...
if(  (pos>=180) || (pos<=0) ){
inc=inc*(-1); // multiplica el valor de inc x -1
}

// Instrucción 5: Imprime el valor de pos
Serial.println(pos);
}
