#include "MaxHardware_controller.h"
MaxHardware_controller m;
#define botao 0
void setup() {
  m.begin();
  m.tft.fillScreen(TFT_RED);
  delay(300);
  m.tft.fillScreen(TFT_GREEN);
  delay(300);
  m.tft.fillScreen(TFT_BLUE);
  delay(300);
  m.tft.fillScreen(TFT_BLACK);
}
void loop() {
  m.mapTouch(true);
  m.tft.setCursor(20, 80);
}

