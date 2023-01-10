#ifndef EinkDisplay_h
#define EinkDisplay_h
#include "EPD_1in9.h"
#include "Sensor.h"

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
  int digits[4];
  bool needUpdate = false;

  void setData(int *);

public:
  EinkDisplay();
  ~EinkDisplay();
  virtual void loop();

  void setNumbers(int, int);
};

#endif