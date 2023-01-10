#ifndef Sensor_h
#define Sensor_h

#include <Arduino.h>

class Sensor
{
public:
  virtual ~Sensor() {}
  virtual void loop(void) = 0;
};

#endif