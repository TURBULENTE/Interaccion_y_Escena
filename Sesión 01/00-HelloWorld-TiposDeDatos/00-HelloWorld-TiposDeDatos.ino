

String miTexto= "hola"; 
char miLetra= 'a';
int miNumero= 10;
float miDecimal= 0.356;
bool miBoolean = 'false';

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

misInstrucciones();
}



void misInstrucciones(){
Serial.println(miTexto);
Serial.println(miLetra);
Serial.println(miNumero);
Serial.println(miDecimal);
Serial.println(miBoolean);
delay(200);
}
