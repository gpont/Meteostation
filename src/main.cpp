#include <Arduino.h>
#include <LowPower.h>
#include <EinkDisplay.h>

#include "SensorBattery.h"
#include "SensorCO2.h"
#include "SensorTemHum.h"

#define PWD_PIN 2
#define TEMP_PIN 4
#define LED_CO2_PIN 3
#define BATTERY_PIN 5 // TODO check pin

EinkDisplay *display;

SensorBattery sensorBattery(BATTERY_PIN);
SensorCO2 *sensorCO2;
SensorTemHum sensorTemHum(TEMP_PIN);

void setup()
{
  pinMode(LED_CO2_PIN, OUTPUT);

  sensorCO2 = new SensorCO2(PWD_PIN);
  display = new EinkDisplay();
}

void loop()
{
  sensorCO2->loop();
  sensorTemHum.loop();
  sensorBattery.loop();

  display->setNumbers(
      floor(sensorTemHum.tempC),
      floor(sensorTemHum.humidity));
  display->setLowPowerIndicator(!sensorBattery.isNormal);

  digitalWrite(LED_CO2_PIN, sensorCO2->isNormal ? LOW : HIGH);

  display->loop();

  // Sleep on 8 seconds
  LowPower.idle(
      SLEEP_8S,
      ADC_OFF,
      TIMER2_OFF,
      TIMER1_OFF,
      TIMER0_OFF,
      SPI_OFF,
      USART0_OFF,
      TWI_OFF);
}
