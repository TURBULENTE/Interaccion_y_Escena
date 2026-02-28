/*---------------------------------------------------------------------------------------------
In this example we send an array of numbers as a Message to another ESP32
  Example for sending messages from the ESP8266/ESP32 to a remote ESP8266/ESP3
  Using Open Sound Control (OSC) library for the ESP8266/ESP32
  Example adapted by Citlali Hernández (@turbulente) for teaching purposes, 2024. 
  This example code is in the public domain.
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
const IPAddress outIp(192, 168, 8, 18);  // remote IP of the device that is going to listen and receive the message
const unsigned int outPort = 9999;       // remote port to receive OSC
const unsigned int localPort = 8888;     // local port to listen for OSC packets (actually not used for sending)

int const noPixels = 5;
float miArray[noPixels];
int randNum;

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));

  /*for (int i = 0; i < noPixels; i++) {
    randNum = random(10);
    miArray[i] = randNum;
    Serial.println(miArray[i]);
  }*/
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

 for (int i = 0; i < noPixels; i++) {
    randNum = random(10);
    miArray[i] = randNum;
  }

  // Sending OSC messages:
  OSCMessage msg("/myMessage");  // Define the id of the message
  for (int i = 0; i < noPixels; i++) {
    msg.add(miArray[i]);
  }
  //msg.add(valueButton);  // add a value to the message
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp);
  Udp.endPacket();
  msg.empty();
  delay(500);
}
