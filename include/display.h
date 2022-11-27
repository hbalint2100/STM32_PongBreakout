#pragma once
#include "stm32f429i_discovery_lcd.h"
#include "stm32f429i_discovery_ts.h"

#define HEIGHT 320
#define WIDTH 240

void displayInit();
void menu();
void printMsg(uint8_t *);
void swapDisplayedLayer();
void selectInactiveLayer();