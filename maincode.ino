#include <Arduino.h>

#include "displayLCD.h"
#include "binMonitoring.h"
#include "myservo.h"

#define plasticBottle "bottle"
#define waterBottle "waterbottle"
#define metalCan "can"


const long interval = 1000;
unsigned long prevMills = 0;


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(2000);

  initLCD();
  initSensors();
  initServo();
  delay(2000);
}

void loop() {
  unsigned long currentMills = millis();

  if(currentMills - prevMills >= interval) {

    if (Serial.available() > 0) {
      String command = Serial.readStringUntil('\n');
      command.trim();
      if (command.equals(plasticBottle) || command.equals(waterBottle))
      {
        Serial.println("Bottle detected");
        displayWaste(command.c_str());
        bottleServo();
        tokenDisplay();
      } else if (command.equals(metalCan)) {
        displayWaste(command.c_str());
        Serial.println("Can detected");
        canServo();
        tokenDisplay();
      } else {
        Serial.println("Invalid command: " + command);
        displayWaste(command.c_str());
        bottleServo();
        tokenDisplay();
      }
    }

    if(canBinDistance() < 30) {
      alarmDisplay("Non-metal");
      buzzerStart();
    } else {
      buzzerStop();
    }
 
    if(bottleBinDistance() < 30) {
      alarmDisplay("Metal");
      buzzerStart();
    } else {
      buzzerStop();
    }

    (doorIRs() == 0) ? doorServo_Open() : doorServo_Close();

    waitingDisplay();
    prevMills = currentMills;
  }
}