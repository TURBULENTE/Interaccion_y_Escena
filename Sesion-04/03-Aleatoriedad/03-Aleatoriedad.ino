int num;

void setup() {
Serial.begin(9600);
randomSeed(analogRead(A0));
}

void loop() {
num= random(13);
Serial.println(num);
delay(500);
}
