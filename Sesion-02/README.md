# Inputs y Rangos

Presentación de Clase : [Aquí](https://e.pcloud.link/publink/show?code=XZ5qo3Zct86Bs0g7ij4kw90nNgCX0csKrYk)

Uno de los principios en la computación física es la Transducción o la conversión de una forma de energía en otra. Los transductores son los elementos principales de un sistema de computación física.
-Input Transducers
-Output Transducers

Cuando conectamos un sensor, normalmente estamos transformando una acción física o comportamiento del entorno en una señal de electricidad. Posteriormente, nuestro microcontrolador transforma esa variación eléctrica en una señal digital. 

Para poder leer los sensores tenemos que identificar si se trata de un sensor de **lectura digital o analógica**. Tenemos que buscar información sobre el sensor, comúnmente en su DATASHEET. Algunos sensores requieren de LIBRERÍAS específicas para poder acceder a sus valores.

Un sensor digital nos dará el valor entero: 0 ò 1
Un sensor analógico no dará un valor dentro del rango: 0 a 1023.

## **Actividades de clase: **

1) Botón DIY
- Construir el circuito de un Botón con cinta de cobre.
- Hacer la lectura digital del sensor, con el comando digitalRead();

2) Sensor de Presión DIY
- Construir el circuito de un sensor de presión utilizando un material piezoresistivo.
- Hacer la lectura analógica del sensor, con el comando analogRead();
- Identificar el rango: mínimo y máximo

3) Map (Mapaje)
- Construir el circuito de un led, conectado a un pin PWM (~)
- Utilizar el comando map, para transformar el rango de entrada (0 - 1023) al rango de salida (0 - 255).

4) Sensor LDR
- Conectar el módulo LDR. Este sensor ya viene integrado en una placa PCB junto con componentes que estabilizan su señal. 
https://www.institutodigital.com.br/produto/modulo-sensor-ldr-de-luminosidade-foto-resistor/<img width="250" alt="image" src="https://github.com/user-attachments/assets/1ae84c01-6c13-41e1-a82b-de94a23310db" />
- Hacer la lectura analógica del sensor, con el comando analogRead();
- Analizar el rango con máxima y mínima intensidad de luz.

5) Sensor Capacitivo
Un sensor capacitivo de tipo touch sensor detecta la presencia del cuerpo humano aprovechando sus propiedades eléctricas. Cuando nos acercamos o tocamos el sensor, nuestro cuerpo actúa como una segunda placa de un capacitor, alterando el campo eléctrico del sensor y modificando su capacitancia. Es este cambio en la capacitancia lo que el circuito detecta y registra como una variación en la medición.

Existen sensores capacitivos fabricados como el siguiente módulo de Adafruit:
<a href="https://www.adafruit.com/product/1375">
  <img src="https://cdn-shop.adafruit.com/970x728/1374-09.jpg" width="250" alt="Sensor"/>
</a>

- O el siguiente módulo del KIT:
<a href="https://wiki.keyestudio.com/Ks0398_keyestudio_EASY_plug_Ultimate_Starter_Kit_for_Arduino_STEM_EDU#capacitive-touch">
  <img width="230" alt="image" src="https://github.com/user-attachments/assets/6d2bd80a-50b4-4a3c-971c-f2f40d49f872" />
</a>

En la clase construiremos un sensor capacitivo DIY utilizando un material conductivo y la librería "Capacitive Sensor" de Paul Badger. 



