/*
 * OLEDChart.cpp
 *
 *  Created on: 20.07.2019
 *      Author: Johannes
 */

#include "OLEDChart.h"

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, change Adafruit_SSD1306.h");
#endif



OLED_Chart::OLED_Chart() {
	// TODO Auto-generated constructor stub

}

OLED_Chart::~OLED_Chart() {
	// TODO Auto-generated destructor stub
}

OLED_Chart::OLED_Chart(uint8_t screenHight, uint8_t screenWidth, int arR[],int Size):display(screenWidth,screenHight, &Wire, oledreset) {
screenhight=screenHight;
screenwidth=screenWidth;
size=Size;

}

void OLED_Chart::init() {
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	display.clearDisplay();
}


void OLED_Chart::drawDataLine() {
	display.clearDisplay();
	drawcoordinates();
	int YZero1 = screenhight / 2;
	float max = findMax();
	float min = findMin();
	float biggest;
	if (max >= abs(min)) {
		biggest = max;
	} else {
		biggest = abs(min);
	}

	float divisor = biggest / ((screenhight / 2)-2);

	int step = screenwidth / (size - 1);

	for (int i = 0; i < size - 1; i++) {

		int y1 = (floor(arr[i] / divisor) * -1) + YZero1;
		int y2 = (floor(arr[i + 1] / divisor) * -1) + YZero1;

		display.drawLine(i * step, y1, (i + 1) * step, y2, WHITE);

	}
	display.display();
}

void OLED_Chart::drawcoordinates() {

	int middle = screenhight / 2;
	int hightquarter = screenhight / 4;

	int widthquarter = screenwidth / 4;

	display.drawLine(0, middle, screenwidth, middle, WHITE);
	display.drawLine(0, hightquarter, screenwidth / 26, hightquarter, WHITE);
	display.drawLine(0, hightquarter * 3, screenwidth / 26, hightquarter * 3, WHITE);

	display.drawLine(0, 0, 0, 96, WHITE);
	display.drawLine(widthquarter, middle - 3, widthquarter, middle + 3, WHITE);
	display.drawLine(widthquarter * 2, middle - 3, widthquarter * 2, middle + 3, WHITE);
	display.drawLine(widthquarter * 3, middle - 3, widthquarter * 3, middle + 3, WHITE);
	display.drawLine(widthquarter * 4, middle - 3, widthquarter * 4, middle + 3, WHITE);
}

int OLED_Chart::findMax() {
	int i;

	int max = arr[0];

	for (i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}

	}

	return max;
}

int OLED_Chart::findMin() {
	int i;

	int min = arr[0];

	for (i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}

	}

	return min;
}

void OLED_Chart::addNewValue(int newValue) {
	int i = 0;
	for (i = 0; i < size - 1; i++) {

		arr[i] = arr[i + 1];

	}
	arr[size - 1] = newValue;
}

void OLED_Chart::printArray() {
	int i = 0;
	for (i = 0; i < size; i++) {

		Serial.print(arr[i]);
		Serial.print(", ");

	}
	Serial.println();
}
