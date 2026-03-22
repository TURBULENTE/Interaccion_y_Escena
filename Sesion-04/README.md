# Actuadores Parte II
[Presentación de clase](https://e.pcloud.link/publink/show?code=XZ8kMGZvdlddFfvMl4LB0bw49ba5bzXI9xX)

## Ejercicios de programación
- [ ] [Aleatoriedad](Sesion-04/03-Aleatoriedad)
- [ ] [Ciclo For](Sesion-04/03-cicloFor)

## Tiras LED
Las tiras led indexables nos permiten enviar información de manera independiente a cada uno de los leds, o también llamados píxeles.
Uno de los chips más comunes es el "WS2812" y para comprender su funcionamiento, como siempre, es importante revisar tanto su Datasheet,como las especificaciones de la tira que compremos. 

A tomar en cuenta cuando compramos una nueva tira:
- Número de leds (pixels)
- Voltaje necesario
- Wattaje de consumo. Normalmente se especifica W/M (por metro).
- Qué tipo de codificación de color trabaja. 
- Circuito recomendado. A veces se recomienda añadir una resitencia y una capacitor. 

Librerías recomendadas:
[Adafruit Neopixel](https://github.com/adafruit/Adafruit_NeoPixel)

[FastLed](https://github.com/FastLED/FastLED)

Ejercicios:
- [ ] [Hola Neopixels - Aleatoriedad](Sesion-04/03-HolaNeopixels-Aleatoriedad)
- [ ] [El coche fantástico](Sesion-04/03-Neopixel-Coche-Fantastico) 

## Motores DC
Los motores DC nos permiten regular tanto dirección como velocidad de movimiento. 
Para poder controlarlo, necesitaremos de un driver que utiliza el chip L298N. La base de su funcionamiento es conocido como “Puente H” que se encarga de invertir la polaridad del motor, reflejándose esto en la dirección del movimiento.

- [ ] [Direcciones](Sesion-04/03-DCMotor_Direcciones)
- [ ] [Aceleración](Sesion-04/03_DC_Aceleracion)



