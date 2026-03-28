# Integrar Inputs y Ouputs en un solo proyecto

## Conceptualizar una interacción
- Para poder conceptualizar nuestras interfaces podemos hacer uso del lenguaje visual propuesto por Marije Baalman en su sitio web: [https://composinginteractions.art/](https://composinginteractions.art/)
- 
-  tanto las instrucciones de nuestro sistema, como las acciones de nuestrx usuarix, el feedback y componentes necesarios 



## Motores Stepper
- Referencia Oficial de Arduino [Stepper Motors](https://docs.arduino.cc/learn/electronics/stepper-motors/)
- Referencia Luis Llamas - [Motor 28ByJ-48](https://www.luisllamas.es/motor-paso-paso-28byj-48-arduino-driver-uln2003/)
## Comunicación OSC

### Ejercicio Enviar-Recibir

Arduino A) *Sender*
Tenemos un potenciómetro conectado y hacemos lectura analógica
Enviamos los datos a través de un mensaje OSC

Arduino B) *Receiver*
Tenemos un stepper motor conectado.
Variaremos la dirección del giro de acuerdo al valor recibido. 

