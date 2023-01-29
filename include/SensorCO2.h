#ifndef SensorCO2_h
#define SensorCO2_h
#include "Sensor.h"
#include "MHZ19PWM.h"

class SensorCO2 : public Sensor
{
  MHZ19PWM *mhz19_pwm;
  const float NORMAL_CO2_LEVEL = 1100.0;
  const float MIDDLE_CO2_LEVEL = 800.0;

public:
  float co2ppm;
  bool isNormal = true;

  SensorCO2(int pwmpin);
  ~SensorCO2();
  virtual void loop();
};

#endif