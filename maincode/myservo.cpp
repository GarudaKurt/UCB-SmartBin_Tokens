#include "myservo.h"
#include <stddef.h>

#include <Servo.h>
#include <Arduino.h>

Servo servoMain;
Servo servoDischarge;
//Servo servoDoor;
//Servo smToken;
//Servo mdToken;
//Servo lgToken;

#define pinServo_Main 5
#define pinServo_Discharge 6
#define pinServo_Door 4;
//#define pinServo_sm 3
//#define pinServo_md A2
//#define pinServo_lg A3

void initServo() {
  servoMain.attach(pinServo_Main);
  servoMain.write(90); //default position

  servoDischarge.attach(pinServo_Discharge);
  servoDischarge.write(90); //default position

  //servoDoor.attach(pinServo_Door);
  //servoDoor.write(90);
  
  //smToken.attach(pinServo_sm);
  //smToken.write(90);
  
  //mdToken.attach(pinServo_md);
  //mdToken.write(90);
  
  //lgToken.attach(pinServo_lg);
  //lgToken.write(90);
  
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

// void doorServo_Open() {
//   servoDoor.write(180);
// }

// void doorServo_Close() {
//   servoDoor.write(90);
// }

// void smTokenServo() {
//   smToken.write(360);
// }

// void mdTokenServo() {
//   mdToken.write(360);
// }

// void lgTokenServo() {
//   lgToken.write(360);
// }



