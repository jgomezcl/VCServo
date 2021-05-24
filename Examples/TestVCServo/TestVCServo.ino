
#include "VCServo.h"

VCServo s;

int i;

void setup() {
  s.attach(9, 540, 2450);
}

void loop() {

  if (!s.isRunning())
  {
    i++;
    if (i == 4)
      i = 0;

    if (i == 0)
      s.moveTo(0, 500);

    if (i == 1)
      s.moveTo(180, 2000);

    if (i == 2)
      s.moveTo(60, 1000);

    if (i == 3)
      s.moveTo(90, 1000);

  }

  s.run();
}
