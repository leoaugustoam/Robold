#include <SoftwareSerial.h>

SoftwareSerial mySerial(10 , 11);
int IN1 = 12 ;
int IN2 = 13 ;
int IN3 = 7 ;
int IN4 = 6 ;
int PWM1 = 11;
int PWM2 = 5;
int vel = 0;
String recebido;
int passos = 0;
int val;
int valanterior = 2;
int flagin = 5;
int flagpasso = 1;
int diff;
int k = 1;
int pos = 0;

String leString() {
  String conteudo = "";
  char caractere;
  while (mySerial.available() > 0) {
    caractere = mySerial.read();
    if (caractere != '\n') {
      conteudo.concat(caractere);
    }
    delay(10);
  }
  Serial.print("Recebi: ");
  Serial.println(conteudo);
  return conteudo;
}

void interrupcao() {
  Serial.println("int");
  if (!digitalRead(2) && flagin == 0) {
    passos++;
    Serial.print("passos");
    Serial.println(passos);
  }
  if (!digitalRead(2) && flagin == 1) {
    passos--;
    Serial.print("passos");
    Serial.println(passos);
    if (passos == 0) {
      flagin = 3;
      Serial.println("fim dos passos");
    }
  }
}

void setup()
{
  Serial.begin(115200);
  mySerial.begin(115200);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(2, INPUT);
  pinMode(9, OUTPUT);
  attachInterrupt(0, interrupcao, FALLING);
}
void loop()
{

  if (mySerial.available() > 0) {
    recebido = leString();
  }
  /*val = recebido.toInt();
    pos=val-k*passos;
    Serial.print("Valor: ");
    Serial.println(val);
    Serial.print("Pos ");
    Serial.println(pos);
    /* Serial.print("Valor+999: ");
    Serial.println(val + 999);
    Serial.print("Valor+55555: ");
    Serial.println(val + 555555);*/

  if (recebido == "m0") {
    analogWrite(PWM2 , 255);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    flagin = 5;
  }
  if (recebido == "m1") {
    analogWrite(PWM2 , 255);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    flagin = 5;
  }
  if (recebido == "mx") {
    analogWrite(PWM2 , 255);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    flagin = 5;
  }

  if (recebido == "mr") {
    //Serial.println("debug");
    analogWrite(PWM2 , 255);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    flagin = 5;
    passos=0;
  }

  if (recebido == "ma") {
    //Serial.println("debug");
    analogWrite(PWM2 , 255);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    //Serial.println("+++");
    flagin = 0;
  }
  if (recebido == "mp") {
    analogWrite(PWM2 , 255);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    flagin = 1;
  }
  if (recebido == "mv") {
    if (flagin == 1) {
      analogWrite(PWM2 , 255);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    if (flagin == 3) {
      analogWrite(PWM2 , 255);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      digitalWrite(9, HIGH);
      delay(1000);
      digitalWrite(9, LOW);
    }
  }
}


