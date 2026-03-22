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
#define LED_PIN 6    // definimos el número de pin PWM
#define LED_COUNT 8  // el número de píxeles en nuestra tira


Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)

void setup() {
  Serial.begin(9600);
  pixels.begin();             // Inicializamos la tira led
  pixels.setBrightness(100);  // Definimos su brillo (Max 255)
}

void loop() {
  // Ciclo for para iluminar del pixel 0 al 7
  for (int i = 0; i < 8; i++) {
    pixels.clear();  //Apagamos todos los pixels
    pixels.setPixelColor(i, pixels.Color(100, 0, 100));
    //argumentos de la función setPixelColor:
    // numéro de pixel,pixels.color (r,g,b)
    delay(50);
    pixels.show();  //Se encienden los pixels que hemos programado
  }

  // Ciclo for para iluminar del pixel 7 al 0
  for (int i = 7; i >= 0; i--) {
    pixels.clear();  //Apagamos todos los pixels
    pixels.setPixelColor(i, pixels.Color(100, 0, 100));
    delay(50);
    pixels.show();  //Se encienden los pixels que hemos programado
  }
}
