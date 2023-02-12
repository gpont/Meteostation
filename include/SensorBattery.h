#ifndef SensorBattery_h
#define SensorBattery_h
#include "Sensor.h"

class SensorBattery : public Sensor
{
  const float LOW_BATTERY_V_LEVEL = 0.5;

  int battery_pin;

public:
  bool isNormal = true;

  SensorBattery(int battery_pin);
  ~SensorBattery();
  virtual void loop();
};

#endif