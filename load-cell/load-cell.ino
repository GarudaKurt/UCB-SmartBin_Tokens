//Author: Rob Tillaart

#include "HX711.h"
//#include <LiquidCrystal_I2C.h> // library for LCD
//LiquidCrystal_I2C lcd(0x27, 16, 2);

const int CDP = A0; // Data pin
const int CSP = A1; // Clock pin
HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(CDP, CSP);

  // Replace this value with your calibration factor obtained from calibration
  scale.set_scale(420.00); // Calibration factor for accurate gram measurements
  scale.tare(); // Reset the scale to 0

  //lcd.init();
  //lcd.backlight();
}

void loop() {
  float weightInGrams = scale.get_units(10); // Weight directly in grams
  Serial.print("Total weight: ");
  Serial.println(weightInGrams);

  //lcd.setCursor(5, 0);
  //lcd.print("Berat:");
  //lcd.setCursor(5, 1);
  //lcd.print(weightInGrams, 2); // Display with two decimal places
  //lcd.print(" g");
  
  delay(100);
}
