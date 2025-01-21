#ifndef __DISPLAY__H
#define __DISPLAY__H
#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

void initLCD();
void displayWaste(const char * message);
void alarmDisplay(const char * message);
void waitingDisplay();
void tokenDisplay();

#endif