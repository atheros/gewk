#include "Arduino.h"
#include "modules/display.h"
#include "modules/sensors.h"
#include "modules/pumps.h"

void setup()
{
	sensorsInit();
	pumpsInit();
	displayInit();
}

// The loop function is called in an endless loop
void loop()
{
	sensorsRun();
	pumpsRun();
	displayRun();
}
