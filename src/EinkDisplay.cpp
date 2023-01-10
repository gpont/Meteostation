#include <Wire.h>
#include "EinkDisplay.h"

EinkDisplay::EinkDisplay() : digits{0, 0, 0, 0}
{
  Wire.begin();
  GPIOInit();
  EPD_1in9_init();
  // TODO: test and select method
  EPD_1in9_lut_DU_WB();
}

void EinkDisplay::loop()
{
  if (needUpdate)
  {
    for (unsigned int i = 0; i < sizeof(digits) / sizeof(digits[0]); i++)
    {
      // TODO: test and select methods
      EPD_1in9_Write_Screen((unsigned char *)DIGITS_MAP[digits[i]]);
    }

    needUpdate = false;
  }
}

void EinkDisplay::setData(int numbers[4])
{
  for (int i = 0; i < 4; i++)
  {
    if (numbers[i] != digits[i])
    {
      digits[i] = numbers[i];
      needUpdate = true;
    }
  }
}

void EinkDisplay::setNumbers(int first, int second)
{
  int data[] = {first / 10,
                first % 10,
                second / 10,
                second % 10};
  setData(data);
}

EinkDisplay::~EinkDisplay()
{
}