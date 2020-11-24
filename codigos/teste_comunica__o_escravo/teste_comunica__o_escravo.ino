#include <SoftwareSerial.h>
String recebido;

String leString() // FUNÇÃO DO MESTRE #
{
  String conteudo = "";
  char caractere;
  while (Serial.available() > 0)
  {
    caractere = Serial.read();
    if (caractere != '\n')
    {
      conteudo.concat(caractere);
    }
    delay(1);
  }
  Serial.print("Recebi: ");
  Serial.println(conteudo);
  return conteudo;
}

void setup() {
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0)
  {
    recebido = leString();
  }
  /*if (recebido == "comunicacao") {
    Serial.println("DDD REFPG100X");
    recebido = "";
  }*/
  Serial.write("teste A");
  delay(1000);
  Serial.write("teste b");
  delay(1000);
  Serial.write("teste c");
  delay(1000);
  Serial.write("teste d");
  delay(1000);
}
