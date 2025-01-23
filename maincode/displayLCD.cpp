#include "displayLCD.h"

#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

void initLCD(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Waiting...");
}

void displayWaste(const char * message) {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Waste Detected");
  lcd.setCursor(2,1);
  lcd.print("Type: ");
  lcd.print(message);
}

void alarmDisplay(const char * message) {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print(message);
  lcd.print(" bin full");
  lcd.setCursor(2, 1);
  lcd.print("Action Required!");
}

void waitingDisplay() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Waiting....");
}

void tokenDisplay() {
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Smart Waste Bin");
  lcd.setCursor(3,1);
  lcd.print("Get Tokens in!");
  for(int i = 15; i >= 0; i--) {
    lcd.setCursor(8,2);
    lcd.print("  ");
    lcd.setCursor(8,2);
    lcd.print(i);
    delay(1000);
  }
}
