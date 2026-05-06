/* En este código veremos cómo enviar un mensaje OSC utilizando la librería ArduinoOSC
disponible en el siguiente repositorio: https://github.com/hideakitai/ArduinoOSC
Aquí enviaremos un solo mensaje integer.
Código por Citlali Hernández, para la asignatura de Interacción y Escena con Arduino
del Postgrau en Escena i Tecnologia Digital, 2026*/


#include <ArduinoOSCWiFi.h>  // Incluimos la librería ArduinoOSC

const char* ssid = "__nombre_Wifi__";      // el nombre de neustra señal Wifi
const char* pwd = "__password_wifi__";          //password de la wifi 
const IPAddress ip(192, 168, 8, 100);  // IP que asignamos a esta Arduino WiFi

const char* dest_ip = "192.168.8.101";  // IP del receptor
const int dest_port = 9000;             // el puerto por donde enviaremos

int valorPote;  // una variable para almacenar el valor del potenciómetro

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Iniciando...");

  // Primero configuramos
  WiFi.config(ip);
  WiFi.begin(ssid, pwd);
  Serial.println("Intentando conectar...");

  int intentos = 0;  // Una variable para almacenar intentos de conexión

  //. Mientras la placa se conecta, imprime unos puntitos suspensivos . . .
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    intentos++;
    if (intentos > 20) {  // Intentamos 20 veces conectarnos, si no, imprimimos un mensaje de Timeout!
      Serial.println("\nTimeout");
      WiFi.begin(ssid, pwd);  // reintenta
      intentos = 0;
    }
  }

  // Cuando nuestra placa Arduino WiFi se conecte correctamente, imprime:
  Serial.println("\nConectado! IP: " + WiFi.localIP().toString());
}


void loop() {
  valorPote = analogRead(A0);  //leemos el valor del potenciómetro
  Serial.println(valorPote);   // imprimimos el valor del potenciómetro
  enviar(valorPote);           // enviamos el valor del potenciómetro
  delay(50);                  // esperamos un poco antes de volver a comenzar el loop
}


// - - - Mis Funciones - - - //

void enviar(int valor) {  // en esta función hemos añadido la variable local "valor"
  OscWiFi.send(dest_ip, dest_port, "/mensaje", valor);
  // Argumentos de OscWifi.send ( ip destino, puerto destino, nombre del mensaje, el valor)
}
