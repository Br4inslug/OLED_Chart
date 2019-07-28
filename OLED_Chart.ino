/* This code works with MLX90614 (GY906) and OLED screen
 * It measures both ambient and object temperature in Fahrenheit and display it on the screen
 * Please visit www.surtrtech.com for more details
 */

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include "OLEDChart.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels --- ###### GROßES DISPLAY
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//#define SCREEN_WIDTH 128 // OLED display width, in pixels --- ###### KLEINES DISPLAY
//#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

int sizeArr=15;
int arr[15] = {0};

OLED_Chart oledchart(SCREEN_HEIGHT,SCREEN_WIDTH,arr,sizeArr);


void setup() {
	Serial.begin(115200);
	oledchart.init();


}

void loop() {

	oledchart.drawDataLine();

//	oledchart.addNewValue((rand() % 80) -40);//test with negative values

	oledchart.addNewValue((rand() % 80) );//test without negative values

	Serial.println();
	oledchart.printArray();
	delay(500);


}
