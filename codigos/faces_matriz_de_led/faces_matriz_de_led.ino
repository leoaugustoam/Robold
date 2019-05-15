// Inladen van de ledcontrol bibliotheek.
#include "LedControl.h"

LedControl lc = LedControl(13, 12, 11, 5);
//************************
//  Definição das faces
//************************

// olho neutro
byte neutral_eye[8] = {B00000000,
                       B00011000,
                       B00111100,
                       B01111110,
                       B01111110,
                       B00111100,
                       B00011000,
                       B00000000
                      };

// olho esbugalhado
byte spooky_eye[8] = {B00111100,
                      B01111110,
                      B11111111,
                      B11111111,
                      B11111111,
                      B11111111,
                      B01111110,
                      B00111100
                     };

// olho fechado (para cima)
byte closed_eye_up[8] = {B00000000,
                         B00001100,
                         B00011000,
                         B00011000,
                         B00011000,
                         B00011000,
                         B00001100,
                         B00000000
                        };

// olho fechado (para baixo)
byte closed_eye_down[8] = {B00000000,
                           B00001100,
                           B00001100,
                           B00000110,
                           B00000110,
                           B00001100,
                           B00001100,
                           B00000000
                          };

// boca feliz            //parte 1
byte happy_mouth[24] = { B00000000,
                         B00000000,
                         B00000000,
                         B00000000,
                         B01100000,
                         B00110000,
                         B00011000,
                         B00001100,
                         //parte 2
                         B00001110,
                         B00000110,
                         B00000110,
                         B00000110,
                         B00000110,
                         B00000110,
                         B00000110,
                         B00001100,
                         //parte 3
                         B00001100,
                         B00011000,
                         B00110000,
                         B01100000,
                         B00000000,
                         B00000000,
                         B00000000,
                         B00000000
                       };


// boca triste           //parte 1
byte sad_mouth[24] = {   B00000000,
                         B00000000,
                         B00000000,
                         B00000000,
                         B00000110,
                         B00001100,
                         B00011000,
                         B00110000,
                         //parte 2
                         B00110000,
                         B01100000,
                         B01100000,
                         B01100000,
                         B01100000,
                         B01100000,
                         B01100000,
                         B00110000,
                         //parte 3
                         B00110000,
                         B00011000,
                         B00001100,
                         B00000110,
                         B00000000,
                         B00000000,
                         B00000000,
                         B00000000
                     };

// boca muito feliz           //parte 1
byte very_happy_mouth[24] = { B00000000,
                              B00000000,
                              B01110000,
                              B01111100,
                              B01100110,
                              B01100110,
                              B01100011,
                              B01100011,
                              //parte 2
                              B01100011,
                              B01100011,
                              B01100011,
                              B01100011,
                              B01100011,
                              B01100011,
                              B01100011,
                              B01100011,
                              //parte 3
                              B01100011,
                              B01100011,
                              B01100110,
                              B01100110,
                              B01111100,
                              B01110000,
                              B00000000,
                              B00000000
                            };

// boca neutra                //parte 1
byte neutral_mouth[24] = {    B00000000,
                              B00000000,
                              B00010000,
                              B00010000,
                              B00010000,
                              B00010000,
                              B00010000,
                              B00010000,
                              //parte 2
                              B00010000,
                              B00010000,
                              B00010000,
                              B00010000,
                              B00010000,
                              B00010000,
                              B00010000,
                              B00010000,
                              //parte 3
                              B00010000,
                              B00010000,
                              B00010000,
                              B00010000,
                              B00010000,
                              B00010000,
                              B00000000,
                              B00000000
                         };

// língua para fora      //parte 1
byte tongue_mouth[24] = {B00000000,
                         B00000000,
                         B00000100,
                         B11001110,
                         B01111110,
                         B00111110,
                         B00011100,
                         B00001100,
                         //parte 2
                         B00001110,
                         B00000110,
                         B00000110,
                         B00000110,
                         B00000110,
                         B00000110,
                         B00000110,
                         B00001100,
                         //parte 3
                         B00001100,
                         B00011000,
                         B00110000,
                         B01100000,
                         B00000000,
                         B00000000,
                         B00000000,
                         B00000000
                        };

// boca aberta             //parte 1
byte opened_mouth[24] = {  B00000000,
                           B00000000,
                           B00000000,
                           B00000000,
                           B00000000,
                           B00000000,
                           B00000000,
                           B00000000,
                           //parte 2
                           B00000000,
                           B00011100,
                           B00100010,
                           B01000001,
                           B01000001,
                           B00100010,
                           B00011100,
                           B00000000,
                           //parte 3
                           B00000000,
                           B00000000,
                           B00000000,
                           B00000000,
                           B00000000,
                           B00000000,
                           B00000000,
                           B00000000
                        };

//*****************
// Setup do Arduino
//*****************
void setup()
{
  //inicializar displays (configurar a intensidade de brilho e limpar tudo)
  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);
  lc.shutdown(1, false);
  lc.setIntensity(1, 1);
  lc.clearDisplay(1);
  lc.shutdown(2, false);
  lc.setIntensity(2, 1);
  lc.clearDisplay(2);
  lc.shutdown(3, false);
  lc.setIntensity(3, 1);
  lc.clearDisplay(3);
  lc.shutdown(4, false);
  lc.setIntensity(4, 1);
  lc.clearDisplay(4);

  //iniciar comunicação serial
  Serial.begin(115200);

}

//***************
// Loop principal
//***************
void loop()
{

  display_mouth(happy_mouth);
  delay(1000);
  display_mouth(sad_mouth);
  delay(1000);
  display_mouth(very_happy_mouth);
  delay(1000);
  display_mouth(tongue_mouth);
  delay(1000);
  display_mouth(opened_mouth);
  delay(1000);
  display_mouth(neutral_mouth);
  delay(1000);
  /*
    if (Serial.available())  //verificar se foi recebido algum dado
    {
    char cmd = Serial.read();

    if(cmd == ':') {
      display_eyes(neutral_eye, neutral_eye);
    }
    if(cmd == ';') {
      display_eyes(neutral_eye, closed_eye_up);
    }
    if(cmd == '8') {
      display_eyes(spooky_eye, spooky_eye);
    }
    if(cmd == ')'){
      display_mouth(happy_mouth);
    }
    if(cmd == '('){
      display_mouth(sad_mouth);
    }
    if((cmd == 'D')||(cmd == 'd')){
      display_mouth(very_happy_mouth);
    }
    if((cmd == 'p')||(cmd == 'P')){
      display_mouth(tongue_mouth);
    }
    if((cmd == 'o')||(cmd == 'O')){
      display_mouth(opened_mouth);
    }
    if(cmd == '|'){
      display_mouth(neutral_mouth);
    }

    }*/
}


//*******************
// Funções auxiliares
//*******************

//mudar olhos
void display_eyes(byte right_eye[], byte left_eye[]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(3, i, left_eye[i]);
    lc.setRow(4, i, right_eye[i]);
  }
}


//mudar boca
void display_mouth(byte mouth[]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, mouth[i]);
    lc.setRow(1, i, mouth[i + 8]);
    lc.setRow(2, i, mouth[i + 16]);
  }
}
