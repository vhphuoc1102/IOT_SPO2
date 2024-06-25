#include <Arduino.h>
#include "mode.h"

#define TFT_DC 2
#define TFT_CS 15
// #define TFT_CS 25
// #define TFT_RST 27
// #define TFT_DC 26
// #define TFT_MOSI 13
// #define TFT_MISO 12
// #define TFT_CLK 14

int idx;      // Index for the normal mode.
int cidx = 0; // Index for the options inside the setting.
int normModLen;
std::map<int, mrender> mMap = {
    {-1, displayMSetting},
    {0, displayMIntro},
    {1, displayMMain},
};
// Uncomment this to change the initialization for different LCD versions

// Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;
const int BASE_DELAY = 1000;

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

  // attachInterrupt(digitalPinToInterrupt(BTN_NAV_1), setMode, FALLING);
  // attachInterrupt(digitalPinToInterrupt(BTN_NAV_2), setMode, FALLING);

  tft.begin();
  // tft.setRotation(2);
  tft.fillScreen(ILI9341_BLACK);

  delay(BASE_DELAY);
  Serial.println("Setup complete!");

  // mMap.at(idx)();
}

void loop()
{
  Serial.print("INDEX LOOP: ");
  Serial.println(idx);
  mMap.at(idx)();
}