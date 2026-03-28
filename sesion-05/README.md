# Integrar Inputs y Ouputs en un solo proyecto

## Conceptualizar una interacción
- Para poder conceptualizar nuestras interfaces podemos hacer uso del lenguaje visual propuesto por Marije Baalman en su sitio web: [https://composinginteractions.art/](https://composinginteractions.art/) Las siguientes imágenes corresponden a referencias en su libro Composing Interactions. 

- **Primero**, definiremos de manera general nuestras acciones, y feedback esperado. Para ello definiremos, quién, con qué, acción, y efecto. Usamos los siguientes códigos visuales:
 <img width="1298" height="386" alt="Captura de pantalla 2026-03-28 a las 13 28 33" src="https://github.com/user-attachments/assets/c7215b01-51eb-4521-8f88-1bb732c688a8" />
-  Por ejemplo, si pensamos en la acción de tocar un chelo, podríamos explicar la interacción de esta manera: 
<img width="1442" height="645" alt="concept-example" src="https://github.com/user-attachments/assets/9c96b2a0-c96c-453d-96cc-5c922c439cef" />

- **Segundo**, definiremos la implementación técnica de nuestro sistema. Usaremos los siguientes códigos visuales para definir el objeto, qué tipo de hardware, software, y tipo de conexiones.
  
  <img width="1206" height="367" alt="Captura de pantalla 2026-03-28 a las 13 33 31" src="https://github.com/user-attachments/assets/5a86380f-3e48-41cc-87a7-a3cfd91b9d71" />
- Definiremos también cómo se conecta cada elemento, pudiendo ser en una dirección, dos direcciones, por cable, conexión inalámbrica, o interna por software. Para ello usamos el siguiente lenguaje visual:
<img width="976" height="651" alt="Captura de pantalla 2026-03-28 a las 13 33 50" src="https://github.com/user-attachments/assets/4d1e1676-4aca-4f63-8c36-85b68ddd568e" />
- También podemos especificar el tipo de señales enviadas:
 <img width="1232" height="192" alt="Captura de pantalla 2026-03-28 a las 13 35 21" src="https://github.com/user-attachments/assets/91b2d4d2-dd45-454b-a80e-c9faa4840db7" />

- Por ejemplo, en un sistema donde hay un micrófono, una interfaz se audio, una laptop y un software de procesamiento de audio:
<img width="1272" height="329" alt="Captura de pantalla 2026-03-28 a las 13 35 29" src="https://github.com/user-attachments/assets/7626dfe7-dcbc-4016-98a3-4a26cc059006" />

## Ejercicio:
1. Utiliza el lenguaje visual de Marije Baalman para dejar registro de tu miniproyecto. Dibuja tanto la conceptualización de la interacción, como la implementación física.
2. Toma una foto de tus diagramas y súbelos a tu repositorio. 

---

## Últimos ejemplos de clase, complementarios: 

### Comunicación OSC

#### Ejercicio Enviar-Recibir

**Arduino A) [*Sender*](/sesion-05/04-OSC-Send-ArduinoUNOR4Wifi)**
Tenemos un potenciómetro conectado y hacemos lectura analógica
Enviamos los datos a través de un mensaje OSC

**Arduino B) [*Receiver*](/sesion-05/04-OSC-Receive-ArduinoUNOR4Wifi.ino)**
Tenemos una tira led de 8 píxeles conectada.
Mapearemos el valor recibido del potenciómetro (0-1023), al número de píxeles de la tira para que se enciendan uno en uno de acuerdo a la rotación del potenciómetro. 

### Motores Stepper
Un motor paso a paso es un tipo especial de motor de corriente continua sin escobillas (brushless) cuya posición puede controlarse con precisión.
El principio de funcionamiento de un motor paso a paso se basa en los campos magnéticos. Consta de dos componentes principales: un estator y un rotor. El rotor suele ser un imán permanente y está rodeado por unas bobinas situadas en el estator.
<img width="400" alt="Stepper-Motor-main-components-stator-and-a-rotor" src="https://github.com/user-attachments/assets/a0c2b8c9-19bf-4f7a-9347-cdd37db1177c" />

Imagen:
[How to Mechatronics](https://howtomechatronics.com/tutorials/arduino/stepper-motors-and-arduino-the-ultimate-guide/)

En el IT tenemos dos modelos de stepper motors, el 28BYJ-48 y Nemas 17. Para poder programarlos, requeriremos de un driver que nos permita controlar las bobinas internas del motor. 

En nuestro motor 28BYJ-48 iremos activando una fase a la vez para lograr el avance de nuestro motor:
![arduino-motor-paso-paso-secuencia-1-fase](https://github.com/user-attachments/assets/db2a6883-32ef-48e3-9d64-50985952f7a8)

Ejercicios:
- [x] Comprendemos cómo programar utilizando [Switch Case](/sesion-05/04-switch-case-basics.ino)
- [x] Movemos un stepper en una dirección y controlamos su velocidad [Direcciones y Velocidad](/sesion-05/04_StepperMotor_Direcciones_ino)
- [x] Controlamos la dirección de un stepper con un botón [Botón y Direcciones](/sesion-05/04-StepperMotor-Boton-Velocidad)
- [x] Comprendemos cuántos pasos hacen una vuelta [Ciclos](/sesion-05/04_StepperMotor_Ciclos_y_Direcciones.ino)

Referencias útiles:
- Referencia Oficial de Arduino [Stepper Motors](https://docs.arduino.cc/learn/electronics/stepper-motors/)
- Referencia Luis Llamas - [Motor 28ByJ-48](https://www.luisllamas.es/motor-paso-paso-28byj-48-arduino-driver-uln2003/)
- Referencia How To Mechatronics - [Nema 17](https://howtomechatronics.com/tutorials/arduino/stepper-motors-and-arduino-the-ultimate-guide/)


