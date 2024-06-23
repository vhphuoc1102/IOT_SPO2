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
    while (true)
    {
        Serial.print("INDEX: ");
        Serial.println(idx);

        if (digitalRead(BTN_SETTING) == LOW)
        {
            idx = -1;
            break;
        }
        else if (digitalRead(BTN_NAV_1) == LOW && idx != -1)
        {
            idx = (idx + 1) % normModLen;
            break;
        }
        else if (digitalRead(BTN_NAV_2) == LOW && idx != -1)
        {
            idx = (idx - 1 + normModLen) % normModLen;
            break;
        }
    }
}