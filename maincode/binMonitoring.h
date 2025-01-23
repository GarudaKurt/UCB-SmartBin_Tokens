#ifndef __BINMONITORING__H
#define __BINMONITORING__H

#include <Arduino.h>


void initSensor();
long canBinDistance();
long bottleBinDistance();
int doorIRs();
void buzzerStart();
void buzzerStop();

#endif