//
//    FILE: LMT87.h
//  AUTHOR: Brandon Blair
// VERSION: 1.1.1
//    DATE: 2021-10-01
// PURPOSE: Arduino library initial intended for Universal Battery Charger
//     URL: https://github.com/Jackal28/LMT87
//

//new quick library which calculates the parabolic voltage to temperature relation

#ifndef LMT87_H
#define LMT87_H
//always call arduino.h
#include <Arduino.h>

class LMT87
{
public:
LMT87();

double getCDegree(uint8_t lmtPin, int ADCres, double voltageRef,  int avgAmt);

double getFDegree(uint8_t lmtPin, int ADCres, double voltageRef,  int avgAmt);


private:


double tempA = 0.00, tempB, tempC, tempD, tempE, mVTemp, steps, mVRef;

};

#endif