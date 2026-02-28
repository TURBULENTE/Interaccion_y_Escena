// Botón con resistencia interna de Arduino

int valSensor;
const int led0=9 ;
const int sensor= 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor, INPUT); // Resistencia interna INPUT_PULLUP Si estamos utilizando el diagrama con resistencia externa, entonces solo hace falta escribir INPUT
  pinMode(led0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valSensor = digitalRead(sensor);
  Serial.println(valSensor);
  // delay(250);

  if(valSensor== HIGH){
digitalWrite(led0,  HIGH);
  }else{
digitalWrite(led0, LOW);
  }
}
