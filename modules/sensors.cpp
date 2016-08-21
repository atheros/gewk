/*
 * sensors.cpp
 *
 *  Created on: 07.08.2016
 *      Author: przemek
 */

#include "sensors.h"

#include <Arduino.h>

int sensorsHum0 = 10;
int sensorsHum1 = 8;
int sensorsHum2 = -1;
int sensorsAirTemp;
int sensorsAirHum;
int sensorsWaterTank;


static uint32_t lastTime = 0;

void sensorsInit() {

}

void sensorsRun() {
	uint32_t time = millis();
	if (time < lastTime+1000) {
		return;
	}

	lastTime = time;
	// TODO: Read sensors values.
	sensorsHum0 = (rand() % 13) - 2;
	sensorsHum1 = (rand() % 13) - 2;
	sensorsHum2 = (rand() % 13) - 2;
}

