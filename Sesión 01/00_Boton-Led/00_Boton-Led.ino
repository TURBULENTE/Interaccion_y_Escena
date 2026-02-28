int valorBoton;
int botonPin=7;
int ledPin=13;

void setup() {
  // put your setup code here, to run once:
pinMode(botonPin, INPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
valorBoton= digitalRead(botonPin);
if(valorBoton== HIGH){
  digitalWrite(ledPin, HIGH);
}else{
  digitalWrite(ledPin, LOW);
}
Serial.println(valorBoton);
}
