#include <Wire.h>
#include "EinkDisplay.h"

EinkDisplay::EinkDisplay() : image{
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00, // TODO
                                 0x05, // С°
                                 0x00}
{
  Wire.begin();
  GPIOInit();
  EPD_1in9_init();

  // Clear screen
  EPD_1in9_lut_5S();
  EPD_1in9_Write_Screen(DSPNUM_1in9_off);
  EPD_1in9_lut_GC();
}

void EinkDisplay::loop()
{
  if (needUpdate)
  {
    EPD_1in9_Write_Screen(image);

    needUpdate = false;
  }
}

void EinkDisplay::setData(unsigned char new_image[IMAGE_SIZE])
{
  for (int i = 0; i < IMAGE_SIZE; i++)
  {
    if (new_image[i] != image[i])
    {
      image[i] = new_image[i];
      needUpdate = true;
    }
  }
}

unsigned char getPixel(int number, int order)
{
  return number == -1 ? EMPTY : DIGITS[number][order];
}

void normalizeDigit(int *digits, int i)
{
  if (digits[i] == 0 && (i == 0 || digits[i - 1] == -1))
  {
    digits[i] = -1;
  }
}

void EinkDisplay::setNumbers(float first, float second)
{
  int digitsParsedFirst[] = {
      (int)(first / 100) % 10,
      (int)(first / 10) % 10,
      (int)first % 10,
      (int)(first * 10) % 10};
  for (int i = 0; i < 4; i++)
  {
    normalizeDigit(digitsParsedFirst, i);
  }

  int digitsParsedSecond[] = {
      (int)(second / 10) % 10,
      (int)second % 10,
      (int)(second * 10) % 10};
  for (int i = 0; i < 3; i++)
  {
    normalizeDigit(digitsParsedFirst, i);
  }

  unsigned char new_image[] = {
      getPixel(digitsParsedFirst[0], 1),
      getPixel(digitsParsedFirst[1], 0),
      getPixel(digitsParsedFirst[1], 1),
      getPixel(digitsParsedFirst[2], 0),
      getPixel(digitsParsedFirst[2], 1),
      getPixel(digitsParsedSecond[0], 0),
      getPixel(digitsParsedSecond[0], 1),
      getPixel(digitsParsedSecond[1], 0),
      getPixel(digitsParsedSecond[1], 1),
      getPixel(digitsParsedSecond[2], 0),
      getPixel(digitsParsedSecond[2], 1),
      getPixel(digitsParsedFirst[3], 0),
      getPixel(digitsParsedFirst[3], 1),
      image[12],
      image[13], // С°
      image[14]};

  setData(new_image);
}

EinkDisplay::~EinkDisplay()
{
  EPD_1in9_sleep();
  Wire.end();
  Serial.end();
}