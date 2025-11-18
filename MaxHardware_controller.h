#ifndef MAXHARDWARE_CONTROLLER_H
#define MAXHARDWARE_CONTROLLER_H
#include <TFT_eSPI.h>      
#include <SPI.h>
#include <XPT2046_Touchscreen.h>
#define TX1 200
#define TX2 3950
#define TY1 200
#define TY2 3890
#define LED_PIN 17
class MaxHardware_controller {
  private:
    int T_IRQ = 14;
    int T_CS = 5;
  public:
    int LCD_W = 240;
    int LCD_H = 320;
    TFT_eSPI tft;
    XPT2046_Touchscreen touch;
    MaxHardware_controller();
    void begin();
    /*!
      @param value valor do brilho da tela 0 a 255;
    */
    void setBrightness(uint16_t value);
    /*!
      @param touchX armazena a posicao de toque no eixo X
      @param touchY armazena a posicao de toque no eixo Y
    */
    bool getTouchCoordinates(int& touchX, int& touchY);

    /*!
      @param x1 primeiro valor da posição das abcissas
      @param x2 ultimo valor da posicao das abcissas
      @param y1 primeiro valo da posicao das ordenadas
      @param y2 ultimo valor da posicao das ordenadas     
    */
    bool touchInArea(int X1, int y1, int x2, int y2, int touchX, int touchY);
    
    /*!
      @param showCordinates Se for verdadeiro eira imprimir as posicoes onde foi detectado o toque na tela
    */
    void mapTouch(bool showCoordinates = false);
};
#endif