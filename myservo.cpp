#include "myservo.h"

Servo servoMain;
Servo servoDischarge;
Servo servoDoor;

const int pinServo_Main = 6;
const int pinServo_Discharge = 7;
const int pinServo_Door = 4;

void initServo() {
  servoMain.attach(pinServo_Main);
  servoMain.write(90); //default position

  servoDischarge.attach(pinServo_Discharge);
  servoDischarge.write(90); //default position

  servoDoor.attach(pinServo_Door);
  servoDoor.write(90);
}

void bottleServo() {
  servoMain.write(0);
  delay(5000);
  servoDischarge.write(45);
  delay(2000);
  servoMain.write(90);
  servoDischarge.write(90);
}

void canServo() {
  servoMain.write(180);
  delay(5000);
  servoDischarge.write(45);
  delay(2000);
  servoMain.write(90);
  servoDischarge.write(90);
}

void doorServo_Open() {
  servoDoor.write(180);
}

void doorServo_Close() {
  servoDoor.write(90);
}

