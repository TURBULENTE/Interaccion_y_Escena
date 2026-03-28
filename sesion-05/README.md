# Integrar Inputs y Ouputs en un solo proyecto

## Conceptualizar una interacción
- Para poder conceptualizar nuestras interfaces podemos hacer uso del lenguaje visual propuesto por Marije Baalman en su sitio web: [https://composinginteractions.art/](https://composinginteractions.art/)
- Primero, definiremos de manera general nuestras acciones, y feedback esperado. Paara ello definiremos, quién, con qué, acción, y efecto. Usamos los siguientes códigos visuales:
 <img width="1298" height="386" alt="Captura de pantalla 2026-03-28 a las 13 28 33" src="https://github.com/user-attachments/assets/c7215b01-51eb-4521-8f88-1bb732c688a8" />
-  Por ejemplo, si pensamos en la acción de tocar un chelo, podríamos explicar la interacción de esta manera: 
<img width="1442" height="645" alt="concept-example" src="https://github.com/user-attachments/assets/9c96b2a0-c96c-453d-96cc-5c922c439cef" />

- Después, definiremos los componentes técnicos del sistema. Ejemplo:


## Ejemplos de clase: 

### Motores Stepper
- Referencia Oficial de Arduino [Stepper Motors](https://docs.arduino.cc/learn/electronics/stepper-motors/)
- Referencia Luis Llamas - [Motor 28ByJ-48](https://www.luisllamas.es/motor-paso-paso-28byj-48-arduino-driver-uln2003/)
### Comunicación OSC

#### Ejercicio Enviar-Recibir

**Arduino A) [*Sender*](/sesion-05/04-OSC-Send-ArduinoUNOR4Wifi)**
Tenemos un potenciómetro conectado y hacemos lectura analógica
Enviamos los datos a través de un mensaje OSC

**Arduino B) [*Receiver*](/sesion-05/04-OSC-Receive-ArduinoUNOR4Wifi.ino)**
Tenemos una tira led de 8 píxeles conectada.
Mapearemos el valor recibido del potenciómetro (0-1023), al número de píxeles de la tira para que se enciendan uno en uno de acuerdo a la rotación del potenciómetro. 


