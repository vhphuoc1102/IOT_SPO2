#include "mcommon.h"

void calculate() {}

Params getParams()
{
    Params params;
    params.vHeart = 100;
    params.vO2 = 100;
    return params;
}

void setMode()
{
    // Serial.print("INDEX: ");
    // Serial.println(idx);
    // portENTER_CRITICAL_ISR(&mux);
    while (true)
    {
        if (digitalRead(BTN_SETTING) == LOW)
        {
            idx = -1;
            break;
        }
        else if (digitalRead(BTN_NAV_1) == LOW && idx != -1)
        {
            Serial.println("DEBUG 1: ");
            idx = (idx + 1) % normModLen;
            break;
        }
        else if (digitalRead(BTN_NAV_2) == LOW && idx != -1)
        {
            Serial.println("DEBUG 2: ");
            idx = (idx - 1 + normModLen) % normModLen;
            Serial.println(idx);
            break;
        }
    }

    // mMap.at(idx)();
    // portEXIT_CRITICAL_ISR(&mux);
}

void printText(const char *text, uint16_t color, int x, int y, int textSize)
{
    tft.setCursor(x, y);
    tft.setTextColor(color);
    tft.setTextSize(textSize);
    tft.print(text);
}

void printText(String text, uint16_t color, int x, int y, int textSize)
{
    tft.setCursor(x, y);
    tft.setTextColor(color);
    tft.setTextSize(textSize);
    tft.print(text);
}

void printText(String text, uint16_t color, int x, int y, int textSize, const GFXfont *f)
{
    tft.setCursor(x, y);
    tft.setTextColor(color);
    tft.setTextSize(textSize);
    tft.setFont(f);
    tft.print(text);
}

int getMidXPos(String text, int textSize)
{
    return (tft.width() - (text.length() * textSize * 5)) / 2;
}

int getMidYPos(int textSize)
{
    return (tft.height() - (textSize * 5)) / 2;
}

int getRevXPos(String text, int textSize, int x)
{
    return tft.width() - x - (text.length() * textSize * 5);
}

int getRevYPos(int textSize, int y)
{
    return tft.height() - y - (textSize * 5);
}

int getRevXPosV2(String text, int textSize, int x)
{
    return tft.width() - x - (text.length() * textSize * 12);
}
