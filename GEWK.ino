#include "Arduino.h"
#include "modules/scheduler.h"
#include "modules/display.h"
#include "modules/sensors.h"
#include "modules/pumps.h"

void setup()
{
	schedulerInit();
	sensorsInit();
	pumpsInit();
	displayInit();
}

// The loop function is called in an endless loop
void loop()
{
	schedulerRun();
	sensorsRun();
	pumpsRun();
	displayRun();
}
