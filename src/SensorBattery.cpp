#include "Arduino.h"
#include "SensorBattery.h"

SensorBattery::SensorBattery(int battery_pin)
{
  battery_pin = battery_pin;
}

void SensorBattery::loop()
{
  isNormal = analogRead(battery_pin) > LOW_BATTERY_V_LEVEL;
}

SensorBattery::~SensorBattery() {}