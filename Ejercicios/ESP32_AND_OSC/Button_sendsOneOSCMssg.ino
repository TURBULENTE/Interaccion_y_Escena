/*---------------------------------------------------------------------------------------------

  Open Sound Control (OSC) library for the ESP8266/ESP32
  Example for sending messages from the ESP8266/ESP32 to a remote computer using a button.
  The example is sending "hello, osc." to the address "/test".
  This example code is in the public domain.
  Example adapted by Citlali Hernández (@turbulente) for teaching purposes, 2024. 
--------------------------------------------------------------------------------------------- */
#if defined(ESP8266)
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif
#include <WiFiUdp.h>
#include <OSCMessage.h>

char ssid[] = "xxxx";     // your network SSID (name)
char pass[] = "xxxx";  // your network password

WiFiUDP Udp;                             // A UDP instance to let us send and receive packets over UDP
const IPAddress outIp(192, 168, 8, 53);  //192.168.8.53      // remote IP of your computer
const unsigned int outPort = 9999;       // remote port to receive OSC
const unsigned int localPort = 8888;     // local port to listen for OSC packets (actually not used for sending)

// led & button
int ledPin = 5;
int buttonPin = 33;
float valueButton;

void setup() {
  Serial.begin(115200);
  // PinModes
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
#ifdef ESP32
  Serial.println(localPort);
#else
  Serial.println(Udp.localPort());
#endif
}

void loop() {

  valueButton = digitalRead(buttonPin);
  Serial.println(valueButton);
  if (valueButton == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  sendingOSC(valueButton);
}

void sendingOSC(float val) {
  OSCMessage msg("/test");
  //msg.add("hello, osc.");
  msg.add(val);
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp);
  Udp.endPacket();
  msg.empty();
  delay(500);
}
