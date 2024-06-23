#include "./mcommon/mcommon.h"
void displayMIntro(Adafruit_ILI9341 &tft)
{

    Serial.println("MODE 0 ......");

    tft.fillScreen(ILI9341_BLACK);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.setCursor(0, 0);
    tft.print("M");
    tft.setCursor(20, 0);
    tft.print("I");
    tft.setCursor(40, 0);
    tft.print("N");
    tft.setCursor(60, 0);
    tft.print("T");
    tft.setCursor(80, 0);
    tft.print("O");
    tft.setCursor(100, 0);
    tft.print("R");
    tft.setCursor(120, 0);
    tft.print("A");
    setMode();
}