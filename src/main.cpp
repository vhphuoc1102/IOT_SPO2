#include <Arduino.h>
#include <map>
#include "mode.h"

typedef void (*mrender)(Adafruit_ILI9341 &tft);

// Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
const std::map<int, mrender> mMap = {
    {-1, displayMSetting},
    {0, displayMIntro},
    {1, displayMMain},
};
const int BASE_DELAY = 1000;

int idx;      // Index for the normal mode.
int cidx = 0; // Index for the options inside the setting.
int normModLen;

void setup()
{
  idx = 0;
  normModLen = mMap.size() - 1; // Not count setting mode.

  Serial.begin(115200);

  Serial.println("Starting SPO2 measurement....");
  delay(BASE_DELAY);
  Serial.println("Setting up the system...");

  pinMode(BTN_SETTING, INPUT_PULLUP);
  pinMode(BTN_NAV_1, INPUT_PULLUP);
  pinMode(BTN_NAV_2, INPUT_PULLUP);

  tft.begin();
  tft.setRotation(2);
  tft.fillScreen(ILI9341_BLACK);

  delay(BASE_DELAY);
  Serial.println("Setup complete!");
}

void loop()
{
  mMap.at(idx)(tft);
}