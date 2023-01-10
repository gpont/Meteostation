/* TODO uncomment
#include <unity.h>

#include "SensorCO2.h"

/**
 * Calc pulse time (ReturnTime) by ppm
 * th = pulseIn(_pwm_pin, HIGH, ReturnTime) / 1000;
 * tl = 1004 - th;
 * ppm = 2000 * (th - 2) / (th + tl - 4);
 */
/*
int pulseTime(int pwdValue)
{
  return 500 * (pwdValue + 4);
}

void setUp(void)
{
  // ArduinoFakeReset();
}

void test_loop(void)
{
  // When(Method(ArduinoFake(Client), pulseIn)).AlwaysReturn();

  // Client *clientMock = ArduinoFakeMock(Client);

  SensorCO2 sensorCO2(2);

  // When(Method(ArduinoFake(Client), pulseIn)).AlwaysReturn(pulseTime(600));

  sensorCO2.loop();

  TEST_ASSERT_EQUAL(sensorCO2.co2ppm, 600);
  TEST_ASSERT_EQUAL(sensorCO2.isNormal, true);

  // When(Method(ArduinoFake(Client), pulseIn)).AlwaysReturn(pulseTime(800));

  sensorCO2.loop();

  TEST_ASSERT_EQUAL(sensorCO2.co2ppm, 800);
  TEST_ASSERT_EQUAL(sensorCO2.isNormal, false);
}

int main(int argc, char **argv)
{
  UNITY_BEGIN();

  RUN_TEST(test_loop);

  return UNITY_END();
}
*/