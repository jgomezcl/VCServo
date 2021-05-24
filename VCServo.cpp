
#include <Arduino.h>
#include "VCServo.h"

VCServo::VCServo() {}

uint8_t VCServo::attach(int pin, int min, int max)
{
  _servo.attach(pin, min, max);
  _min = min;
  _max = max;

  _current = 90;    //set start position at 90º
  _target = 90;
  _servo.writeMicroseconds(map(90, 0, 180, _min, _max));
}

void VCServo::detach()
{
  _servo.detach();
}

void VCServo::moveTo(int target)
{
  _target = target;
  _rate = 1000 / DEFAULT_RATE;
}

void VCServo::moveTo(int target, int duration)
{
  if (abs(target - _current) == 0)
    return;

  _target = target;
  _rate = duration / abs(_target - _current);
  _rate = constrain(_rate, 0, 255);
}

void VCServo::run()
{
  if (millis() - _timer > _rate)      //moves one º on every update until it reaches the position
  {
    _timer = millis();

    if (_target > _current)
      _current++;
    else if (_target < _current)
      _current--;

    _servo.writeMicroseconds(map(_current, 0, 180, _min, _max));
  }
}

boolean VCServo::isRunning()
{
  if (_target == _current)
    return false;

  return true;
}
