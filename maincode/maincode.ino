#include <Arduino.h>
#include <HardwareSerial.h>

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
  initSensor();
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
        waitingDisplay();
      } else if (command.equals(metalCan)) {
        String type = "metal";
        type += command.c_str();
        displayWaste(type.c_str());
        Serial.println("Can detected");
        canServo();
        tokenDisplay();
        waitingDisplay();

      } else {
        Serial.println("Invalid command: " + command);
        displayWaste(command.c_str());
        bottleServo();
        tokenDisplay();
        waitingDisplay();

      }
    }

    if(canBinDistance() <= 10) {
      Serial.println("Pass here!");
      Serial.print("Distance ");
      Serial.println(canBinDistance());
      alarmDisplay("Non-metal");
      buzzerStart();
    } else {
      waitingDisplay();
      buzzerStop();
    }
 
    /*if(bottleBinDistance() < 30) {
      alarmDisplay("Metal");
      buzzerStart();
    } else {
      buzzerStop();
    }

    (doorIRs() == 0) ? doorServo_Open() : doorServo_Close();*/
    prevMills = currentMills;
  }
}