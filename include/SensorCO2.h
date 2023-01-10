#ifndef SensorCO2_h
#define SensorCO2_h
#include "Sensor.h"
#include "MHZ19.h"

class SensorCO2 : public Sensor
{
  MHZ19 *mhz19_pwm;
  const int NORMAL_CO2_LEVEL = 600;

public:
  int co2ppm;
  bool isNormal;

  SensorCO2(int pwmpin);
  ~SensorCO2();
  virtual void loop();
};

#endif