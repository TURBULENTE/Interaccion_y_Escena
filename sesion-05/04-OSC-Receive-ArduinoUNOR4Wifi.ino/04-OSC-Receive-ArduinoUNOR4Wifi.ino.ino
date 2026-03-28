/* En este código veremos cómo recibir un mensaje OSC utilizando la librería ArduinoOSC
disponible en el siguiente repositorio: https://github.com/hideakitai/ArduinoOSC
Aquí leeremos un solo mensaje integer, y lo mapearemos a una tira led de 8 píxeles.
Por Citlali Hernández, para la asignatura de Interacción y Escena con Arduino
del Postgrau en Escena i Tecnologia Digital, 2026*/

#include <Adafruit_NeoPixel.h>
#define PIN 6        // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 8  // Popular NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


#include <ArduinoOSCWiFi.h>

const char* ssid = "whiteRabbit";      // el nombre de neustra señal Wifi
const char* pwd = "goodlife";          //password de la wifi
const IPAddress ip(192, 168, 8, 101);  // IP que asignamos a esta Arduino WiFi
const int recv_port = 9000;            // el puerto por donde escuchar
int potPix;
int valor;  // hacemos una variable para almacenar el valor del mensaje recibido

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Iniciando...");

  // Primero configuramos
  WiFi.config(ip);
  WiFi.begin(ssid, pwd);
  Serial.println("Intentando conectar...");

  int intentos = 0;  // Una variable para almacenar intentos de conexión
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    intentos++;
    if (intentos > 20) {  // Intentamos 20 veces conectarnos, si no, imprimimos un mensaje de Timeout!
      Serial.println("\nTimeout");
      WiFi.begin(ssid, pwd);
      intentos = 0;
    }
  }
  // Cuando nuestra placa Arduino WiFi se conecte correctamente, imprime:
  Serial.println("\nConectado! IP: " + WiFi.localIP().toString());

  // con la función subscribe asignamos puerto para escuchar, el nombre del mensaje enviado
  // y el nombre del primer argumento del mensaje, que en este caso lo tenemos en una función llamada alRecibir
  OscWiFi.subscribe(recv_port, "/mensaje", alRecibir);
  //.suscribe espera en orden: i, f, s,
  // es decir, un integer en la primer posición, un float y un string

  pixels.begin();
}

void loop() {
  OscWiFi.update();

  pixels.clear();  // Set all pixel colors to 'off'
  potPix = map(valor, 0, 1023, 0, 7);
  potPix = constrain(potPix, 0, 7);
  pixels.setBrightness(100);
  pixels.setPixelColor(potPix, pixels.Color(100, 0, 100));
  pixels.show();  // Send the updated pixel colors to the hardware.
}


/// Mis Funciones

void alRecibir(const OscMessage& m) {
  valor = m.arg<int>(0);  // m.arg extrae el primer argumento del mensaje OSC recibido
  static unsigned long ultimo = 0;
  unsigned long ahora = millis();
  Serial.println("Recibido: " + String(valor) + " | dt: " + String(ahora - ultimo) + "ms");
  ultimo = ahora;
}