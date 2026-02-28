int sensorPin = 2;
int buttonState;
int receivedData;

void setup() {
  Serial.begin(57600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  buttonState = digitalRead(sensorPin);
  Serial.println(buttonState);

  if (Serial.available() > 0) {
    receivedData = Serial.read();

    if (receivedData == 1) {
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(12, LOW);
    } else if (receivedData == 0) {
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(12, HIGH);
    }
  }
  delay(1000 / 60);  // We synch to the P5JS frameRate (60fps)
}
