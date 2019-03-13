#include <Servo.h>
int sensorPin = A0;
int sensorValue = 0;
int IN1 = 12 ;
int IN2 = 13 ;
int IN3 = 7 ;
int IN4 = 6 ;
int PWM1 = 11;
int PWM2 = 5;
int vel = 0;
int aux1 = 0;
int aux2 = 0;
int ang = 0;

void setup() {
  delay (1500);
  Serial.begin(115200);
  Serial.println("Inicializando...");
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(A0, INPUT);

}



void loop() {

  sensorValue = analogRead(A0);

  aux1 = map(sensorValue, 0, 1023, 0, 255);
  //Serial.print("AUX1: ");
  //Serial.println(sensorValue);
  if (aux1 >= 115 && aux1 <= 140) {
    Serial.print("parado ");
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);

  }

  if (aux1 > 145) {
    vel = map(aux1, 145, 255, 0, 255);
    Serial.print("vel1: ");
    Serial.println(vel);
    analogWrite(PWM2 , vel);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  if (aux1 < 115) {
    vel = map(aux1, 115, 0, 0, 255);
    Serial.print("vel2: ");
    Serial.println(vel);
    analogWrite(PWM2 , vel);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

  }
  //delay(100);
}
