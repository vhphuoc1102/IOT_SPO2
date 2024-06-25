#include "./mcommon/mcommon.h"

void displayMIntro()
{
    Serial.println("MODE 0 ......");

    printText("SPO2", WHITE, getMidXPos("SPO2", 4) - 20, 10, 4);
    tft.drawRGBBitmap(180, 5, heart, 20, 20);
    tft.drawRGBBitmap(180, 30, oxygen, 20, 20);

    printText("NHOM 12", MAGENTA, getMidXPos("NHOM 12", 3), 120, 3);

    printText("Vu Hong Phuoc", CYAN, 10, 160, 1);
    printText("20204847", CYAN, getRevXPos("20204847", 1, 10), 160, 1);

    printText("Tran Bach Luu Duc", CYAN, 10, 180, 1);
    printText("20200180", CYAN, getRevXPos("20200180", 1, 10), 180, 1);

    printText("Chu Tien Thanh", CYAN, 10, 200, 1);
    printText("20204852", CYAN, getRevXPos("20204852", 1, 10), 200, 1);

    printText("CONTINUE...", WHITE, getMidXPos("CONTINUE...", 2), 230, 2);

    setMode();
}