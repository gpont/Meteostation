#include "SensorTemHum.h"

SensorTemHum::SensorTemHum(uint8_t pin)
{
  // TODO check type
  dht = new DHT(pin, DHT11);
  dht->begin();
}

void SensorTemHum::loop()
{
  humidity = dht->readHumidity();
  tempC = dht->readTemperature(false);
}

SensorTemHum::~SensorTemHum()
{
  delete dht;
}