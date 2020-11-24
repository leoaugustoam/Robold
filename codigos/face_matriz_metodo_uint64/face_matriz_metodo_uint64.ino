#include <LedControl.h>

const uint64_t zz[] = {
  0x000041a214080000,
  0x0000102845820000,
  0x0000048a51200000
};
const uint64_t neutro[] = {
  0x000000ff00000000
};
const uint64_t feliz[] = {
  0x000080c060301000,
  0x007eff8100000000,
  0x00000103060c0800
};


LedControl display = LedControl(13, 12, 11, 5);


void setup() {
  display.clearDisplay(0);
  display.shutdown(0, false);
  display.setIntensity(0, 10);
  display.clearDisplay(1);
  display.shutdown(1, false);
  display.setIntensity(1, 10);
  display.clearDisplay(2);
  display.shutdown(2, false);
  display.setIntensity(2, 10);
}


void loop() {
  animacaoZZ(2);

  displayImage1(neutro[0]);
  displayImage2(neutro[0]);
  displayImage3(neutro[0]);
  delay(1000);

  displayImage1(feliz[0]);
  displayImage2(feliz[1]);
  displayImage3(feliz[2]);
  delay(1000);
}


void animacaoZZ(int j) {
  for (int i = 0; i < j; i++) {
    displayImage1(zz[0]);
    displayImage2(zz[1]);
    displayImage3(zz[2]);
    delay(50);
    displayImage1(zz[2]);
    displayImage2(zz[0]);
    displayImage3(zz[1]);
    delay(50);
    displayImage1(zz[1]);
    displayImage2(zz[2]);
    displayImage3(zz[0]);
    delay(50);
  }
}


void displayImage1(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(0, j, i, bitRead(row, j));
    }
  }
}
void displayImage2(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(1, j, i, bitRead(row, j));
    }
  }
}
void displayImage3(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(2, j, i, bitRead(row, j));
    }
  }
}

