/* This example sends and receives messages
to an ArduinoUNO using the WebSerial library.

Sending to Arduino:
A red led lights when moving the mouse over the red side of the canvas.
A blue led lights when moving the mouse over the blue side of the canvas.

Receiving from Arduino:
The state of a button is displayed in text.

Example made by Citlali Hernández - April 2025, 
based on the basic example of the WebSerial Library repository: 
https://github.com/gohai/p5.webserial/
*/

let port;
let connectBtn;

function setup() {
  createCanvas(400, 400);
  background(220);

  port = createSerial();

  // in setup, we can open ports we have used previously
  // without user interaction
  let usedPorts = usedSerialPorts(); //this methods connects the port automatically
  if (usedPorts.length > 0) {
    port.open(usedPorts[0], 57600);
  }
  // any other ports can be opened via a dialog after
  // user interaction (see connectBtnClick below)
  connectBtn = createButton("Connect to Arduino");
  connectBtn.position(5, 10);
  connectBtn.mousePressed(connectBtnClick);
}

function draw() {
  noStroke();
  fill(255, 50, 0);
  rect(0, 0, width / 2, height);

  noStroke();
  fill(0, 180, 255);
  rect(width / 2, 0, width / 2, height);

  ///////// SENDING DATA
  // Here we use the method port.write to send data to ArduinoUNO. In this example depending on the mouse position.
  if (mouseX < width / 2) {
    port.write(1);
  }
  if (mouseX > width / 2) {
    port.write(0);
  }
  ///////// READING DATA
  // reads in complete lines and prints them at the
  // bottom of the canvas
  let str = port.readUntil("\n");
  let valSensor = port.readUntil("\n");
  if (str.length > 0) {
    fill(255);
    text(str, 10, height - 20);
  }

  // changes button label based on connection status
  if (!port.opened()) {
    connectBtn.html("Connect to Arduino");
  } else {
    connectBtn.html("Disconnect");
  }
}

function connectBtnClick() {
  if (!port.opened()) {
    port.open("Arduino", 57600);
  } else {
    port.close();
  }
}
