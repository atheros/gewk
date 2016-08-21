/*
 * display.cpp
 *
 *  Created on: 06.08.2016
 *      Author: przemek
 */

#include "display.h"
#include "sensors.h"

#include <Adafruit_SSD1306.h>


#include "../resources/logo.h"
#include "../resources/DroidSansBold8pt7b.h"
#include "../resources/jar_empty.h"
#include "../resources/jar_full.h"
#include "../resources/pipe.h"
#include "../resources/pump1.h"
#include "../resources/plant.h"
#include "../resources/sensors.h"


//// D/C pin.
//#define OLED_DC     14
//// Chip Select pin.
//#define OLED_CS     16
//// Reset pin.
//#define OLED_RESET  15

// D/C pin.
#define OLED_DC     6
// Chip Select pin.
#define OLED_CS     7
// Reset pin.
#define OLED_RESET  8

#define OLED_W 128
#define OLED_H 64

// Display object.
static Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

static unsigned long lastDisplayRefresh = 0;
static bool isDisplayOn = true;
static volatile uint32_t flag2 = true;

static void drawState();

void displayInit() {
	display.begin(SSD1306_SWITCHCAPVCC);
	display.cp437(true);
	display.setTextColor(1);
	display.setTextSize(1);
	display.setFont(&DroidSansBold8pt7b);

	display.clearDisplay();
	display.drawBitmap(0, 0, IMG_LOGO, IMG_LOGO_W, IMG_LOGO_H,
			1);
	display.display();
	delay(2000);
}

void displayRun() {
	unsigned long time = millis();
	unsigned long delta;
	if (lastDisplayRefresh > time) {
		lastDisplayRefresh = 0;
	}
	delta = time - lastDisplayRefresh;

	// TODO: check state

	// If display is off, there is nothing more to do.
	if (!isDisplayOn) {
		return;
	}

	// Don't run the display code too often.
	if (delta < 200) {
		return;
	}
	lastDisplayRefresh = time;

	if (!flag2) return;

	drawState();


}


void printSensorsHum(int value, int left, int line) {
	char buff[8];
	int16_t x, y;
	uint16_t w, h;

	if (value == -1) {
		sprintf(buff, "N/A");
	} else if (value == -2) {
		sprintf(buff, "ERR");
	} else if (value == 0) {
		sprintf(buff, "DRY");
	} else {
		sprintf(buff, "%4i", value);
	}

	display.getTextBounds(buff, 0, 0, &x, &y, &w, &h);
	display.setCursor(left + 18 - w, line - h);
	display.print(buff);
}

void drawState() {
	display.fillScreen(0);
	display.drawBitmap(4, 30, IMG_JAR_FULL, IMG_JAR_FULL_W, IMG_JAR_FULL_H, 1);
	display.drawBitmap(29, 54, IMG_PIPE, IMG_PIPE_W, IMG_PIPE_H, 1);
	display.drawBitmap(37, 34, IMG_PUMP1, IMG_PUMP1_W, IMG_PUMP1_H, 1);
	display.drawBitmap(67, 54, IMG_PIPE, IMG_PIPE_W, IMG_PIPE_H, 1);
	display.drawBitmap(75, 30, IMG_PLANT, IMG_PLANT_W, IMG_PLANT_H, 1);
	display.drawBitmap(96, 12, IMG_SENSORS, IMG_SENSORS_W, IMG_SENSORS_H, 1);

	// Humidity sensors.
	display.setFont(NULL);
	printSensorsHum(sensorsHum0, 108, 11);
	printSensorsHum(sensorsHum1, 108, 23);
	printSensorsHum(sensorsHum2, 108, 35);

	display.display();
}

