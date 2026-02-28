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
if(botonPin== HIGH){
  digitalWrite(ledPin, HIGH);
  delay(500);
}else{
  digitalWrite(ledPin, LOW);
  delay(500);
}
Serial.println(valorBoton);
}
