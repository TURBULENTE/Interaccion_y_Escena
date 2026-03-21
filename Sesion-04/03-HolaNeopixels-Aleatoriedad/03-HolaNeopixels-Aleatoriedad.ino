/* Usamos la librería "Adafruit Neopixel"
cuya documentación podéis consultar en:
https://github.com/adafruit/Adafruit_NeoPixel

Para identificar qué librería podemos usar con nuestros leds
es importante que identifiquemos el tipo de chip integrado
por ejemplo, en la tira de 8 pixels de clase 
tiene el chip WS2812, uno de los más comunes 
y está presente en las tiras de la marca Adafruit.
*/

#include <Adafruit_NeoPixel.h>

#define PIN 6        // el pin en el que está conectada nuestra tira
#define NUMPIXELS 8  // el número de píxeles que estamos programando

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)

int num;

void setup() {
  Serial.begin(9600);
  // Inicializamos la tira led
  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  //pixels.show();             // Turn OFF all pixels ASAP
  //pixels.setBrightness(50);  // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
num= random(7);
Serial.println(num);
  pixels.clear();  // Set all pixel colors to 'off'
  //Un pixel específico setPixelColor
  pixels.setPixelColor(num, pixels.Color(100, 0, 100));
  delay(500);
  //argumentos de la función setPixelColor:
  // numéro de pixel,pixels.color (r,g,b)

  pixels.show();
}
