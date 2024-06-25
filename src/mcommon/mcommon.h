#ifndef COMMON
#define COMMON
#include <Adafruit_ILI9341.h>
#include <Adafruit_GFX.h>
#include <Fonts/FreeSansBold24pt7b.h>

#include <map>
#include "./assets/assets.h"
// Uncomment this to change the PINs for different LCD versions

#define BTN_SETTING 32
#define BTN_NAV_1 33
#define BTN_NAV_2 25
// #define BTN_NAV_1 16
// #define BTN_NAV_2 17

typedef struct Params
{
    int vHeart;
    int vO2;
} Params;
typedef void (*mrender)();

extern std::map<int, mrender> mMap;
extern Adafruit_ILI9341 tft;
extern int idx;
extern int normModLen;
extern portMUX_TYPE mux;

Params getParams();
void setMode();
void printText(const char *text, uint16_t color, int x, int y, int textSize);
void printText(String text, uint16_t color, int x, int y, int textSize);
void printText(String text, uint16_t color, int x, int y, int textSize, const GFXfont *f);
int getMidXPos(String text, int textSize);
int getMidYPos(int textSize);
int getRevXPos(String text, int textSize, int x);
int getRevYPos(int textSize, int y);
int getRevXPosV2(String text, int textSize, int x);
#endif // COMMON