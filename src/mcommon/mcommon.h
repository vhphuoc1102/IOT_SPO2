#ifndef COMMON
#define COMMON
#include <Adafruit_ILI9341.h>
#include <Adafruit_GFX.h>

#define BTN_SETTING 32
#define BTN_NAV_1 33
#define BTN_NAV_2 25
#define TFT_DC 2
#define TFT_CS 15
// #define BTN_NAV_1 16
// #define BTN_NAV_2 17
// #define TFT_CS 25
// #define TFT_RST 27
// #define TFT_DC 26
// #define TFT_MOSI 13
// #define TFT_MISO 12
// #define TFT_CLK 14

extern int idx;
extern int normModLen;

typedef struct Params
{
    int vHeart;
    int vO2;
} Params;

Params getParams();

void setMode();

#endif // COMMON