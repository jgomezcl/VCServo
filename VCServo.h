
#ifndef VCServo_h
#define VCServo_h

#include <Servo.h>

#define DEFAULT_RATE 90  //rate of movement in º/s (range between 4 and 1000)

class VCServo
{
  public:
    VCServo();
    uint8_t attach(int pin, int min, int max);
    void detach();
    void moveTo(int target);
    void moveTo(int target, int duration);
    void run();
    boolean isRunning();

  private:
    uint16_t _min;          //value in us for 0º
    uint16_t _max;          //value in us for 180º
    uint8_t _target;        //desired postion in º
    uint8_t _current;       //current position in º
    Servo _servo;           //servo object
    unsigned long _timer;   //last position update
    uint8_t _rate;          //update rate
};

#endif
