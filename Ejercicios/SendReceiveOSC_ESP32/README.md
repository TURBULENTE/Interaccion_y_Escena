
#ESP32 One Message Send and Receive between two ESP32 boards

1. Instalar ESP32 en las preferencias de Arduino.
Instrucciones de Espressif: https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html  Usar la development release: https://espressif.github.io/arduino-esp32/package_esp32_dev_index.json


2. Instalar ESP32 Espressif - BOARDS MANAGER

El nombre de las placas en Arduino IDE son: WEMOS Lolin 32 Lite


# Ejemplo 1 -  ESP sends to Processing
- Abrir ejemplo Sending ONE OSC Message
- Cambiar IP por la del ordenador
- Cargar
- Abrir ejemplo Processing 

# Ejemplo 2 ESP sends to another ESP 32
- En una de las ESP's (la que recibirá)
- Cargar el ejemplo “Receiving_OneOSCMessage_ESP32”
- En el monitor serial se imprimirá la IP de la placa, apuntarla (192.168.8.___)
- Abrir el ejemplo  “Sending_OneOSCMessage_ESP32”
- Cambiar en número de IP correspondiente a la ESP que recibe
- Cargar el programa
 
#IMPORTANTE
- En ambos casos, el modelo en la IDE es Wemos Lolin 32 Lite.
- Cambiar la velocidad a 115200

