#include <Arduino.h>
#include "EinkDisplay.h"
#include "SensorCO2.h"

#define PWD_PIN 4

EinkDisplay display;
SensorCO2 sensorCO2(PWD_PIN);

void setup()
{
}

void loop()
{
  sensorCO2.loop();

  // display.setNumbers(12, 34);

  display.loop();
}