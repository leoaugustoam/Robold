#include <Servo.h>

int CH2 = 8;
int CH4 = 9;
int IN1 = 12 ;
int IN2 = 13 ;
int IN3 = 7 ;
int IN4 = 6 ;
int PWM1 = 11;
int PWM2 = 5;
//pino 10 - servo

unsigned long channel2 = 0;
unsigned long channel4 = 0;

Servo myservo;

int vel = 0;
int aux1 = 0;
int aux2 = 0;
int ang = 0;

void setup() {
  delay (1500);
  Serial.begin(9600);
  Serial.println("Inicializando...");
  pinMode (CH2, INPUT);
  pinMode (CH4, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);

  myservo.attach(10);

     myservo.write(90);
}

void checkTransmitter()
{
  channel2 = (pulseIn (CH2, HIGH, 100000)) / 10;
  channel4 = (pulseIn (CH4, HIGH, 100000)) / 10;
}


void loop() {
  checkTransmitter();
  //Serial.print("ch2: ");
  //Serial.println(channel2);
  //Serial.print("ch4: ");
  //Serial.println(channel4);

  // 87 -95 = 90            <10 0 >170 180
  if(channel2 <20 ){
    aux2 = 95; 
  }
  aux2 = map(channel4, 102, 188, 117, 63);// 180 - 0
  Serial.print("                            SERVO: ");
  Serial.println(aux2);


  if (aux2 >= 83 && aux2 <= 94) {
     ang = 92;
     myservo.write(ang);

  }
  if (aux2 > 94 && aux2 < 117) {
     ang = aux2;
     myservo.write(ang);
  }
  if (aux2 >= 63 && aux2 < 83) {
     ang = aux2;
     myservo.write(ang);
  }


  aux1 = map(channel2, 101, 187, 255, 0);
  //Serial.print("VELOCIDADE:");
  //Serial.println(aux1);
  if ((aux1 >= 115 && aux1 <= 145) || aux1 > 260) {
    //Serial.println("                                                                                  PARADO");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);

  }

  if (aux1 > 145 && aux1 <260) {
    //Serial.print("                                                                                  FRENTE COM VELOCIDADE : ");
    vel = map(aux1, 145, 255, 60, 255);
    //Serial.println(vel);

    analogWrite(PWM1 , vel);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN1, LOW);
    analogWrite(PWM2 , vel);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  if (aux1 < 115) {
    //Serial.print("                                                                                  TRAS COM VELOCIDADE");
    vel = map(aux1, 115, 0, 60, 255);
    //Serial.println(vel);
    analogWrite(PWM1 , vel);
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
    analogWrite(PWM2 , vel);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

  }
}
