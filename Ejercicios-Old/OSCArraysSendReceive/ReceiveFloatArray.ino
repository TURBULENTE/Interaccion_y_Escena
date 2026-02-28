/*---------------------------------------------------------------------------------------------

  Open Sound Control (OSC) library for the ESP8266/ESP32
Example adapted from ESP8266ReceiveMessage Library
In this example, an ESP32 is receiving two messages from another ESP32
  This example code is in the public domain.

--------------------------------------------------------------------------------------------- */
#ifdef ESP8266
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>

char ssid[] = "xxxx";     // your network SSID (name)
char pass[] = "xxxx";  // your network password

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;
const unsigned int localPort = 9999;  // local port to listen for UDP packets

OSCErrorCode error;

// Variables to keep messages received
int const noPixels = 5;
float miArray[noPixels];

void setup() {
  
  Serial.begin(115200);

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

  Serial.print("Board connected! My IP is: ");
  Serial.println(WiFi.localIP());  // Here we print the IP assigned to the board.
  delay(2000);                     // Wait 2 seconds, write down the board's IP!
}




void loop() {
  OSCMessage msg;
  int size = Udp.parsePacket();
  if (size > 0) {
    while (size--) {
      msg.fill(Udp.read());
    }
    if (!msg.hasError()) {
      msg.dispatch("/myMessage", oscReceive);
    } else {
      error = msg.getError();
      Serial.print("error: ");
      Serial.println(error);
    }
  }
}

// Unpacketing messages and setting them to specific variables
void oscReceive(OSCMessage &msg) {

 for (int i = 0; i < noPixels; i++) {
    miArray[i] = msg.getFloat(i);
    Serial.println(miArray[i]);
  }
}
