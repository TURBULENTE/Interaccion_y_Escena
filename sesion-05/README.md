# Integrar Inputs y Ouputs en un solo proyecto

## Conceptualizar una interacción
- Para poder conceptualizar nuestras interfaces podemos hacer uso del lenguaje visual propuesto por Marije Baalman en su sitio web: [https://composinginteractions.art/](https://composinginteractions.art/)
- Primero, definiremos de manera general nuestras acciones, y feedback esperado. Ejemplo:

- Después, definiremos los componentes técnicos del sistema. Ejemplo:

## Ejemplos de clase: 

### Motores Stepper
- Referencia Oficial de Arduino [Stepper Motors](https://docs.arduino.cc/learn/electronics/stepper-motors/)
- Referencia Luis Llamas - [Motor 28ByJ-48](https://www.luisllamas.es/motor-paso-paso-28byj-48-arduino-driver-uln2003/)
### Comunicación OSC

#### Ejercicio Enviar-Recibir

Arduino A) [*Sender*](/sesion-05/04-OSC-Receive-ArduinoUNOR4Wifi.ino)

Tenemos un potenciómetro conectado y hacemos lectura analógica
Enviamos los datos a través de un mensaje OSC

Arduino B) *Receiver*
Tenemos una tira led de 8 píxeles conectada.
Mapearemos el valor recibido del potenciómetro (0-1023), al número de píxeles de la tira para que se enciendan uno en uno de acuerdo a la rotación del potenciómetro. 


