/*
 * scheduler.cpp
 *
 *  Created on: 22.08.2016
 *      Author: przemek
 */


#include "scheduler.h"
#include <DS1307RTC.h>
#include <Wire.h>
#include <TimeLib.h>

static void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}

void schedulerInit() {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      while(true) delay(10000);
    }
}

void schedulerRun() {
	tmElements_t tm;

	if (RTC.read(tm)) {
		Serial.print("Ok, Time = ");
		print2digits(tm.Hour);
		Serial.write(':');
		print2digits(tm.Minute);
		Serial.write(':');
		print2digits(tm.Second);
		Serial.print(", Date (D/M/Y) = ");
		Serial.print(tm.Day);
		Serial.write('/');
		Serial.print(tm.Month);
		Serial.write('/');
		Serial.print(tmYearToCalendar(tm.Year));
		Serial.println();
	} else {
		Serial.println("DS1307 read error!  Please check the circuitry.");
	}
}



