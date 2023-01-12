#include "SensorCO2.h"
#include "MHZ19.h"

SensorCO2::SensorCO2(int pwmpin)
{
  mhz19_pwm = new MHZ19(pwmpin);
  loop();
}

void SensorCO2::loop()
{
  co2ppm = mhz19_pwm->getPpmPwm();
  isNormal = co2ppm <= (isNormal ? NORMAL_CO2_LEVEL : MIDDLE_CO2_LEVEL);
}

SensorCO2::~SensorCO2()
{
  delete mhz19_pwm;
}