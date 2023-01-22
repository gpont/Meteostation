#include <Arduino.h>
#include <LowPower.h>

#include "EinkDisplay.h"
#include "SensorCO2.h"
#include "SensorTemHum.h"

#define PWD_PIN 2
#define TEMP_PIN 4
#define LED_CO2_PIN 3

EinkDisplay display;
SensorCO2 sensorCO2(PWD_PIN);
SensorTemHum sensorTemHum(TEMP_PIN);

void setup()
{
  Serial.begin(9600);
  pinMode(LED_CO2_PIN, OUTPUT);
}

void loop()
{
  sensorCO2.loop();
  sensorTemHum.loop();

  Serial.print(floor(sensorTemHum.tempC));
  Serial.print("C, ");
  Serial.print(floor(sensorTemHum.humidity));
  Serial.print("%, ");
  Serial.print(sensorCO2.isNormal ? "normal" : "not normal");
  Serial.print(", co2: ");
  Serial.print(sensorCO2.co2ppm);
  Serial.println(";");

  // TODO check for nan

  display.setNumbers(
      floor(sensorTemHum.tempC),
      floor(sensorTemHum.humidity));

  digitalWrite(LED_CO2_PIN, sensorCO2.isNormal ? LOW : HIGH);

  display.loop();

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
