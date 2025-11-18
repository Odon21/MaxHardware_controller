#include "TFT_eSPI.h"
#include "MaxHardware_controller.h"

MaxHardware_controller::MaxHardware_controller(): tft(TFT_eSPI()), touch(T_CS, T_IRQ) {}
void MaxHardware_controller::begin(){
  tft.begin();
  touch.begin();
  tft.setRotation(0);
  touch.setRotation(2);
  pinMode(LED_PIN, OUTPUT);
  setBrightness(255);
};
void MaxHardware_controller::mapTouch(bool showCoordinates){
  if(touch.touched()){
    TS_Point p =touch.getPoint();
    int x = ((p.x - TX1) * LCD_W) / (TX2 - TX1);
    int y = ((p.y - TY1) * LCD_H) / (TY2 - TY1);
    if(((x >=0) &&(x <= LCD_W)) && (y>=0) && (y <=LCD_H)){
      Serial.print("X: ");
      Serial.print( x);
      Serial.print(" | Y: ");
      Serial.println( y);
      tft.drawPixel(x, y, tft.color565(random(0, 255), random(0,255), random(0,255)));
      if (showCoordinates) {
        tft.setTextColor(TFT_GREEN, TFT_BLACK);
        tft.setTextSize(1);
        tft.setCursor(LCD_W-80, LCD_H-10, 1);
        tft.printf("X:%d Y:%d ", x, y);  // Mostra coordenadas
      }
    }
  }
};
bool MaxHardware_controller::touchInArea(int x1, int y1, int x2, int y2, int touchX, int touchY){
  if ((touchX >= x1 && touchX <= x2) && (touchY >= y1 && touchY <= y2)) {
    return true;
  }
  return false;
};
void MaxHardware_controller::setBrightness(uint16_t value){
  if((value >=0) && (value<=255)){
    analogWrite(LED_PIN, value);
  }
};
bool MaxHardware_controller::getTouchCoordinates(int& touchX, int& touchY){
  if(touch.touched()){
    TS_Point p =touch.getPoint();
    int touchX = ((p.x - TX1) * 240) / (TX2 - TX1);
    int touchY = ((p.y - TY1) * 320) / (TY2 - TY1);
    if(((touchX >=0) &&(touchX <= 240)) && (touchY>=0) && (touchY <=320)){
      return true;
    }
  }return false;
};