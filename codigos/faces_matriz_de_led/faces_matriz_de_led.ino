// Inladen van de ledcontrol bibliotheek.
#include <LedControl.h>

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
byte sad_mouth[24] = { B00000000,
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
byte happy_mouth[24] = {   B00000000,
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
                              B00001110,//
                              B00111110,//
                              B01100110,//
                              B01100110,//
                              B11000110,//
                              B11000110,//
                              //parte 2
                              B11000110,
                              B11000110,
                              B11000110,
                              B11000110,
                              B11000110,
                              B11000110,
                              B11000110,
                              B11000110,
                              //parte 3
                              B11000110,
                              B11000110,
                              B01100110,
                              B01100110,
                              B00111110,
                              B00001110,
                              B00000000,
                              B00000000
                            };

// boca neutra                //parte 1
byte neutral_mouth[24] = {    B00000000,
                              B00000000,
                              B00001000,
                              B00001000,
                              B00001000,
                              B00001000,
                              B00001000,
                              B00001000,
                              //parte 2
                              B00001000,
                              B00001000,
                              B00001000,
                              B00001000,
                              B00001000,
                              B00001000,
                              B00001000,
                              B00001000,
                              //parte 3
                              B00001000,
                              B00001000,
                              B00001000,
                              B00001000,
                              B00001000,
                              B00001000,
                              B00000000,
                              B00000000
                         };

// língua para fora      //parte 1
byte tongue_mouth[24] = {B00000000,
                         B00000000,
                         B00100000,
                         B01110011,
                         B01111110,
                         B01111100,
                         B00111000,
                         B00110000,
                         //parte 2
                         B01110000,
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
byte bz1[24] = {          B01100000,
                          B00110000,
                          B00011000,
                          B00001100,
                          B00011000,
                          B00110000,
                          B01100000,
                          B00110000,

                          B00011000,
                          B00001100,
                          B00011000,
                          B00110000,
                          B01100000,
                          B00110000,
                          B00011000,
                          B00001100,

                          B00011000,
                          B00110000,
                          B01100000,
                          B00110000,
                          B00011000,
                          B00001100,
                          B00011000,
                          B00110000
               };
byte bz2[24] = {         B00110000, B01100000, B00110000,
                         B00011000,
                         B00001100,
                         B00011000,
                         B00110000,
                         B01100000,

                         B00110000,
                         B00011000,
                         B00001100,
                         B00011000,
                         B00110000,
                         B01100000,
                         B00110000,
                         B00011000,

                         B00001100,
                         B00011000,
                         B00110000,
                         B01100000,
                         B00110000,
                         B00011000,
                         B00001100,
                         B00011000
               };
byte bz3[24] = {          B00011000,
                          B00110000,
                          B01100000,
                          B00110000,
                          B00011000,
                          B00001100,
                          B00011000,
                          B00110000,

                          B01100000,
                          B00110000,
                          B00011000,
                          B00001100,
                          B00011000,
                          B00110000,
                          B01100000,
                          B00110000,

                          B00011000,
                          B00001100,
                          B00011000,
                          B00110000,
                          B01100000,
                          B00110000,
                          B00011000,
                          B00001100
               };
byte bz4[24] = {          B00001100,
                          B00011000,
                          B00110000,
                          B01100000,
                          B00110000,
                          B00011000,
                          B00001100,
                          B00011000,

                          B00110000,
                          B01100000,
                          B00110000,
                          B00011000,
                          B00001100,
                          B00011000,
                          B00110000,
                          B01100000,

                          B00110000,
                          B00011000,
                          B00001100,
                          B00011000,
                          B00110000,
                          B01100000,
                          B00110000,
                          B00011000
               };
byte bz5[24] = {          B00001100,
                          B00011000,
                          B00110000,
                          B01100000,
                          B00110000,
                          B00011000,
                          B00001100,
                          B00011000,

                          B00110000,
                          B01100000,
                          B00110000,
                          B00011000,
                          B00001100,
                          B00011000,
                          B00110000,
                          B01100000,

                          B00110000,
                          B00011000,
                          B00001100,
                          B00011000,
                          B00110000,
                          B01100000,
                          B00110000,
                          B00011000
               };
byte bz6[24] = {          B00011000,
                          B00001100,
                          B00011000,
                          B00110000,
                          B01100000,
                          B00110000,
                          B00011000,
                          B00001100,

                          B00011000,
                          B00110000,
                          B01100000,
                          B00110000,
                          B00011000,
                          B00001100,
                          B00011000,
                          B00110000,

                          B01100000,
                          B00110000,
                          B00011000,
                          B00001100,
                          B00011000,
                          B00110000,
                          B01100000,
                          B00110000
               };
byte bz7[24] = {         B00110000,
                         B00011000,
                         B00001100,
                         B00011000,
                         B00110000,
                         B01100000,
                         B00110000,
                         B00011000,

                         B00001100,
                         B00011000,
                         B00110000,
                         B01100000,
                         B00110000,
                         B00011000,
                         B00001100,
                         B00011000,

                         B00110000,
                         B01100000,
                         B00110000,
                         B00011000,
                         B00001100,
                         B00011000,
                         B00110000,
                         B01100000
               };
byte bz8[24] = {         B01100000,
                         B00110000,
                         B00011000,
                         B00001100,
                         B00011000,
                         B00110000,
                         B01100000,
                         B00110000,

                         B00011000,
                         B00001100,
                         B00011000,
                         B00110000,
                         B01100000,
                         B00110000,
                         B00011000,
                         B00001100,

                         B00011000,
                         B00110000,
                         B01100000,
                         B00110000,
                         B00011000,
                         B00001100,
                         B00011000,
                         B00110000
               };




byte olho1[8] = {
  B00000000,
  B00111100,
  B01000010,
  B10011001,
  B10011001,
  B01000010,
  B00111100,
  B00000000
};

byte olho2[8] = {
  B00000000,
  B00111100,
  B01011010,
  B10011001,
  B10000001,
  B01000010,
  B00111100,
  B00000000
};

byte olho3[8] = {
  B00000000,
  B00111100,
  B01000010,
  B10000001,
  B10011001,
  B01011010,
  B00111100,
  B00000000
};
byte dente1[24] = {         B00000000,
                            B00000000,
                            B00000011,
                            B00000110,
                            B00001100,
                            B00001100,
                            B00001100,
                            B00001100,

                            B00001100,
                            B00001100,
                            B00001100,
                            B00001100,
                            B00001100,
                            B00001100,
                            B00001100,
                            B00001100,


                            B00001100,
                            B00001100,
                            B00001100,
                            B00001100,
                            B00000110,
                            B00000011,
                            B00000000,
                            B00000000
                  };
byte dente2[24] = {         B00000000,
                            B00000000,
                            B00000011,
                            B00000110,
                            B00001100,
                            B00001100,
                            B00001100,
                            B00111100,

                            B01001100,
                            B01001100,
                            B00111100,
                            B00001100,
                            B00001100,
                            B00111100,
                            B01001100,
                            B01001100,


                            B00111100,
                            B00001100,
                            B00001100,
                            B00001100,
                            B00000110,
                            B00000011,
                            B00000000,
                            B00000000
                  };


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

void loop()
{
  animacaoZ();
}

void animacaoZ() {
  display_mouth(bz1);
  delay(50);
  display_mouth(bz2);
  delay(50);
  display_mouth(bz3);
  delay(50);
  display_mouth(bz4);
  delay(50);
  display_mouth(bz5);
  delay(50);
  display_mouth(bz6);
  delay(50);
  display_mouth(bz7);
  delay(50);
  display_mouth(bz8);
  delay(50);
}

void display_eyes(byte right_eye[], byte left_eye[]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(3, i, left_eye[i]);
    lc.setRow(4, i, right_eye[i]);
  }
}

void display_mouth(byte mouth[]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, mouth[i]);
    lc.setRow(1, i, mouth[i + 8]);
    lc.setRow(2, i, mouth[i + 16]);
  }
}
