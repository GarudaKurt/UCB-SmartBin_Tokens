#include "displayLCD.h"

void initLCD(){
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Waiting...");
}

void displayWaste(const char * message) {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.println("Waste Detected");
  lcd.setCursor(2, 1);
  lcd.println(message)
}

void alarmDisplay(const char * message) {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print(message)
  lcd.println(" bin are full");
  lcd.setCursor(0, 1);
  lcd.println("Action Required!")
}

void watingDisplay() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Waiting....");
}

void tokenDisplay() {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Smart Waste Bin");
  lcd.setCursor(2,1);
  lcd.print("Get Tokens!");
  lcd.setCursor(3,2);
  for(int i = 10; i >= 0; i--) {
    lcd.print(i);
    delay(1000);
  }
}
