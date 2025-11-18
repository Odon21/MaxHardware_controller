This library is only for LCD TFT 240x320 ILI9341_DRIVER 
#define ILI9341_DRIVER
Configuration
  Arduino/libraries/TFT_eSPI/User_Setup.h

PINS
  #define TFT_MISO 19  //SPI
  #define TFT_MOSI 23  //SPI
  #define TFT_SCLK 18  //SPI
  #define TFT_CS   15  // Chip select control pin
  #define TFT_DC    2  // Data Command control pin
  #define TFT_RST   4  // Reset
  #define T_IRQ  14    // Touch interupt
  #define T_CS  5      // Touch chip selector

* SPI_Frequency
  #define SPI_FREQUENCY  27000000
  #define SPI_READ_FREQUENCY  20000000
  #define SPI_TOUCH_FREQUENCY  2500000
