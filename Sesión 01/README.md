
# Hello Arduino

Arduino es una placa PCB que contiene un microcontrolador que nos permite crear y programar circuitos electrónicos. Existen varios modelos, y la manera de conectar y alimentar nuestros circuitos dependerá de ello. 
Podéis consultar el DATASHEET y el PINOUT del modelo que utilizáis en las páginas de referencia. 

- Arduino UNO: (https://docs.arduino.cc/hardware/uno-rev3/)
- Arduino UNO R3: (https://docs.arduino.cc/hardware/uno-rev3/)
- Arduino WIFI: (https://docs.arduino.cc/hardware/uno-r4-wifi/)


## Ejercicios
1. Creamos nuestro primer circuito con un led
2. Comunicación Serial, Hello World!
3. [Programar un led](https://github.com/TURBULENTE/Interaccion_y_Escena/tree/main/Sesi%C3%B3n%2001/00-LED-DigitalWrite) - digitalWrite
4. [Secuencias de leds y funciones](https://github.com/TURBULENTE/Interaccion_y_Escena/tree/main/Sesi%C3%B3n%2001/00-Boton-Secuencias-Led) - delay, digitalWrite, void
5. Creamos el circuito de un botón
6. [Lectura digital de un botón](https://github.com/TURBULENTE/Interaccion_y_Escena/tree/main/Sesi%C3%B3n%2001/00-DigitalReadBoton) - digitalRead
7. Ejercicio Extra - [Serial.println y Tipos de Datos](https://github.com/TURBULENTE/Interaccion_y_Escena/tree/main/Sesi%C3%B3n%2001/00-HelloWorld-TiposDeDatos)

## Programación

### Variables y Tipos de Datos
- [x] Variables: https://docs.arduino.cc/learn/programming/variables
- [x] Variables locales vs. variables globales: https://www.youtube.com/watch?v=8mbyebZwHFc

## Recursos Extra
- [x]  Conectar y Programar un LED: https://arduinogetstarted.com/tutorials/arduino-led-blink
- [x]  Conectar y Programar un botón: https://docs.arduino.cc/built-in-examples/digital/Button

## Hello Electrónica

**¿Cómo fluye la electricidad?**

La electricidad es el flujo de carga eléctrica, lo que significa el movimiento de electrones a través de un material conductor. Estos electrones se mueven de zonas de **carga negativa** a zonas de **carga positiva**, creando una corriente eléctrica.

**Circuitos**

Para que los electrones fluyan, debe existir una ruta. Específicamente, el circuito debe ir desde la fuente de carga negativa, atravesar el conductor y regresar a la fuente de carga positiva. Un ejemplo de esto es una bombilla, una batería, un interruptor y un cable. Si se cierra el interruptor, el circuito se completa y el terminal negativo de la batería repele los electrones (como se repelen las cargas iguales) y los envía a través del cable hasta la bombilla. Como resultado, la bombilla se enciende y los electrones continúan fluyendo de vuelta al terminal positivo. Cuando el interruptor está abierto, el circuito no está completo y la electricidad no fluye por los cables.

[![Texto alternativo](https://img.youtube.com/vi/x4pdzG-DHnY/0.jpg)](https://www.youtube.com/watch?v=x4pdzG-DHnY&t=78s)

En esta asignatura utilizaremos una placa de circuitos impresa llamada Arduino UNO que funcionará como nuestra fuente de alimentación para los componentes que conectaremos a ella. El circuito funcionará a 5V.




