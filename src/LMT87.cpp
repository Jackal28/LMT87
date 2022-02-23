//MIT License
//
//Copyright (c) [2021] [Brandon Blair]

//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

#include "LMT87.h"
#include <Arduino.h>


LMT87::LMT87(void){}

double LMT87::getCDegree(uint8_t lmtPin, int ADCres, double voltageRef,  int avgAmt)
{
	//initial variable setup
	mVRef = voltageRef*1000;
	steps = pow(2.0,ADCres);
	//averaging
	for (int i = 0; i < avgAmt; i++)
    {         
	tempA += analogRead(lmtPin);
    }
	tempD = tempA / avgAmt;
    tempA = tempD;
	//start conversion
	tempB = tempA * mVRef;
	tempC = tempB / steps;
	mVTemp = tempC;
	//clearing variables for reuse
	tempA = 0;
	tempB= 0;
	tempC = 0;
	tempD = 0;
	//calculating temperature
	tempA = sq(-13.582);
	tempB = (2230.8 - mVTemp);
	tempC = 4 * 0.00433 * tempB;
	tempD = tempA + tempC;
	tempE = sqrt(tempD);
	//reusing variables
	tempA = 13.582 - tempE;
	tempB = 2 * (-.00433);
	tempC = tempA / tempB;
	tempD = tempC + 30;
  
  return tempD;
}

double LMT87::getFDegree(uint8_t lmtPin, int ADCres, double voltageRef,  int avgAmt)
{
	//initial variable setup
	mVRef = voltageRef*1000;
	steps = pow(2.0,ADCres);
	//averaging
	for (int i = 0; i < avgAmt; i++)
    {         
	tempA += analogRead(lmtPin);
    }
	tempD = tempA / avgAmt;
    tempA = tempD;
	//start conversion
	tempB = tempA * mVRef;
	tempC = tempB / steps;
	mVTemp = tempC;
	//clearing variables for reuse
	tempA = 0;
	tempB= 0;
	tempC = 0;
	tempD = 0;
	//calculating temperature
	tempA = sq(-13.582);
	tempB = (2230.8 - mVTemp);
	tempC = 4 * 0.00433 * tempB;
	tempD = tempA + tempC;
	tempE = sqrt(tempD);
	//reusing variables
	tempA = 13.582 - tempE;
	tempB = 2 * (-.00433);
	tempC = tempA / tempB;
	tempD = tempC + 30;
	tempD *= 1.8;
	tempD += 32;
		
  return tempD;
}
