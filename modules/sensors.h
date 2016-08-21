/*
 * sensors.h
 *
 *  Created on: 07.08.2016
 *      Author: przemek
 */

#ifndef MODULES_SENSORS_H_
#define MODULES_SENSORS_H_

extern int sensorsHum0;
extern int sensorsHum1;
extern int sensorsHum2;
extern int sensorsAirTemp;
extern int sensorsAirHum;
extern int sensorsWaterTank;


void sensorsInit();
void sensorsRun();

#endif /* MODULES_SENSORS_H_ */
