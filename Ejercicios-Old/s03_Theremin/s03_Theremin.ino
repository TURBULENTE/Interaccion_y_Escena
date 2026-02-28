const int ldr = A1;
const int buzzer = 9;
int valLDR;
int frecuencia;

void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(buzzer, OUTPUT);
}


void loop() {

  valLDR = analogRead(ldr);
  frecuencia = abs(map(valLDR, 30, 800, 30, 1000));
  Serial.print("Valor del LDR=  ");
  Serial.println(valLDR);
  Serial.print("Valor de la frecuencia= ");
  Serial.println(frecuencia);
  
  if (frecuencia < 60) {
    noTone(buzzer);
  } else {
    tone(buzzer, frecuencia);
    delay(150);
  }
  
}