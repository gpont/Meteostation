#ifndef EinkDisplay_h
#define EinkDisplay_h
#include "EPD_1in9.h"
#include "Sensor.h"

#define IMAGE_SIZE 15

const unsigned char EMPTY = 0x00;
const unsigned char DIGITS[][2] = {
    {0xbf, 0xff}, // 0
    {0x00, 0xff}, // 1
    {0xfd, 0x17}, // 2
    {0xf5, 0xff}, // 3
    {0x47, 0xff}, // 4
    {0xf7, 0x1d}, // 5
    {0xff, 0x1d}, // 6
    {0x21, 0xff}, // 7
    {0xff, 0xff}, // 8
    {0xf7, 0xff}, // 9
};

const unsigned char *const DIGITS_MAP[] = {
    DSPNUM_1in9_W0,
    DSPNUM_1in9_W1,
    DSPNUM_1in9_W2,
    DSPNUM_1in9_W3,
    DSPNUM_1in9_W4,
    DSPNUM_1in9_W5,
    DSPNUM_1in9_W6,
    DSPNUM_1in9_W7,
    DSPNUM_1in9_W8,
    DSPNUM_1in9_W9,
};

class EinkDisplay : public Sensor
{
  bool needUpdate = false;
  unsigned char image[IMAGE_SIZE];

  void setData(unsigned char new_image[]);

public:
  EinkDisplay();
  ~EinkDisplay();
  virtual void loop();

  void setNumbers(float first, float second);
};

#endif