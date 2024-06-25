#include "./mcommon/mcommon.h"
#include <random>
#include <string.h>

int oldVal = 0;
int minVal = 0;
int maxVal = 60;
int range = maxVal - minVal;
int val;
void drawGraph(int &loopCounter);
void drawBPR(int &val);
void displayMMain()
{
    tft.fillScreen(BLACK);
    delay(1000);

    Serial.println("MODE 1 ......");

    int loopCounter = 10;
    while (idx == 1)
    {
        if (digitalRead(BTN_SETTING) == LOW)
        {
            idx = -1;
            return;
        }
        else if (digitalRead(BTN_NAV_1) == LOW && idx != -1)
        {
            Serial.println("DEBUG 1: ");
            idx = (idx + 1) % normModLen;
            return;
        }
        else if (digitalRead(BTN_NAV_2) == LOW && idx != -1)
        {
            Serial.println("DEBUG 2: ");
            idx = (idx - 1 + normModLen) % normModLen;
            Serial.println(idx);
            return;
        }

        val = std::rand() % range + minVal;
        drawBPR(val);
        drawGraph(loopCounter);
        delay(200);
    }
    // setMode();
}

inline void drawGraph(int &loopCounter)
{

    tft.drawLine(loopCounter, tft.height() - oldVal, loopCounter + 1, tft.height() - val, WHITE);
    tft.fillRect(loopCounter + 2, tft.height(), 5, -maxVal, BLACK);

    oldVal = val;

    loopCounter = (loopCounter + 1) % (tft.width() - 20);
}

inline void drawBPR(int &val)
{

    // tft.fillRect(tft.width() - width, 100, width, height, BLACK);
    // printText(String(val), WHITE, tft.width() - width, 100, 2, &FreeSansBold24pt7b);

    int16_t x, y;
    uint16_t w, h;
    tft.setTextWrap(false);
    tft.getTextBounds(String(val), 0, 0, &x, &y, &w, &h);

    Serial.print("VAL: " + String(val));
    Serial.println("WIDTH: " + String(w));
    
}