/*
 * OLEDChart.h
 *
 *  Created on: 20.07.2019
 *      Author: Johannes
 */

#ifndef OLEDCHART_H_
#define OLEDCHART_H_



#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Wire.h"



class OLED_Chart {
public:
	OLED_Chart();
	virtual ~OLED_Chart();
	OLED_Chart(uint8_t screenHight, uint8_t screenWidth, int arR[], int Size);
	void drawDataLine();
	void drawDataLinePositive();
	void drawcoordinates();
	void drawcoordinatesPositive();
	int findMax();
	int findMin();
	void addNewValue(int newValue);
	void printArray();
	void init();

private:
	int arr[15];
	int size=15;
	uint8_t screenhight;
	uint8_t screenwidth;
	uint8_t oledreset = 4;
	Adafruit_SSD1306 display;
};

#endif /* OLEDCHART_H_ */
