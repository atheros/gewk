/*
 * pumps.cpp
 *
 *  Created on: 21.08.2016
 *      Author: przemek
 */
#include "pumps.h"
#include <Arduino.h>


#define PUMP1_PIN	5
#define PUMP2_PIN	4
#define PUMP3_PIN	3

void pumpsInit() {
	pinMode(PUMP1_PIN, OUTPUT);
	pinMode(PUMP2_PIN, OUTPUT);
	pinMode(PUMP3_PIN, OUTPUT);
}


void pumpsRun() {
//	unsigned long time = millis() / 1000;
//	if (time % 3 == 0) {
//		digitalWrite(PUMP1_PIN, HIGH);
//		digitalWrite(PUMP2_PIN, LOW);
//		digitalWrite(PUMP3_PIN, LOW);
//	} else if (time % 3 == 1) {
//		digitalWrite(PUMP1_PIN, LOW);
//		digitalWrite(PUMP2_PIN, HIGH);
//		digitalWrite(PUMP3_PIN, LOW);
//	} else if (time % 3 == 2) {
//		digitalWrite(PUMP1_PIN, LOW);
//		digitalWrite(PUMP2_PIN, LOW);
//		digitalWrite(PUMP3_PIN, HIGH);
//	}
}



