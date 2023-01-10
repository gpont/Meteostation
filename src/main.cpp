#include <Arduino.h>
#include "EinkDisplay.h"
#include "SensorCO2.h"
#include "SensorTemHum.h"

#define PWD_PIN 4
#define TEMP_PIN 5

EinkDisplay display;
SensorCO2 sensorCO2(PWD_PIN);
SensorTemHum sensorTemHum(TEMP_PIN);

void setup()
{
}

void loop()
{
  sensorCO2.loop();
  sensorTemHum.loop();

  display.setNumbers(
      floor(sensorTemHum.tempC),
      floor(sensorTemHum.humidity));

  display.loop();
}