
/* Receiving FOSC Messages from an ESP32, Wemos Lolin 32 Lite Board
 Input: A button connected to a pin in the board
 Output: The bacgkround color changes
 
 This example uses:
 OSCP5 library by Andreas Schlegel
 https://sojamo.de/libraries/oscP5/
 
 Example adapted by Citlali Hernández  2024
 */


// IMPORTING OSC LIBRARIES
import oscP5.*;
import netP5.*;
OscP5 oscP5; // Create an Oscp5 object and name it  "oscP5";
NetAddress myRemoteLocation; // this variable keeps the IP of our computer


color miColor = color(0, 0, 0); // variable used as an output
float [] data ; // array to keep data from osc messages


void setup() {
  size(640, 480); // the size of our canvas
  data = new float[1]; //Defining the number of items in our array


  // Initialize the osc library, adding the port
  oscP5 = new OscP5(this, 9999);

  /*myRemoteLocation needs two parameters,
   the IP of the computer where Processing is running,
   the port number to listen */
  myRemoteLocation = new NetAddress("192.168.8.53", 9999);
}


void draw() {

  background(miColor);
  info();

  colorChange();
  //smiley();
}

/*
 Incoming OSC messages require Processing to be read
 with the oscEvent function that is specific to the library.
 Therefore this function should always be called like this
 */
void oscEvent(OscMessage theOscMessage) {
  // Print the address pattern and the typetag of the received OscMessage
  print("### received an osc message.");
  print(" addrpattern: "+theOscMessage.addrPattern());
  println(" typetag: "+theOscMessage.typetag());

  //Fill the array with the incoming messages
  if (theOscMessage.addrPattern().equals("/test")) { // indicate the ID of the messages
    data[0]=theOscMessage.get(0).floatValue(); //
    // when receiving more than one message we can continue filling the array, for example:
    //  data[1]=theOscMessage.get(1).floatValue();
    println("OSC Messages says= "  + data[0]);
  }
}

// A function to print in the canvas the incoming data from Wekinator
void info() {
  textSize(15);
  fill(255);
  textAlign(LEFT);
  text("OSC Messages Says= " + data[0], 20, height-25);
}

// Example 1
// A function to change a color depending on the received message
void colorChange() {
  if (data[0]==1) {
    miColor=color(255, 0, 0);
  } else if ( data[0]==0) {
    miColor=color(0, 0, 255);
  }
}
