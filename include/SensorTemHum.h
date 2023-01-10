#ifndef TempHumSensor_h
#define TempHumSensor_h
#include "Sensor.h"
#include "DHT.h"

class SensorTemHum : public Sensor
{
private:
  DHT *dht;

public:
  float humidity;
  float tempC;

  SensorTemHum(uint8_t pin);
  ~SensorTemHum();
  virtual void loop();
};

#endif