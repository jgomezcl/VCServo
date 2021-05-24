# VCtrlServo
An Arduino library to control the velocity of servomotors.

The implementation is based on the *millis()* function and the code inside the *loop()* must be non-blocking.

Tested with Arduino UNO but should work well in other platforms.

## Library usage
### Classes

**VCServo** is the main class for controlling a single stepper motor.

### Constructor

**VCServo()**

### Methods

**void attach(int *pin*, int *min*, int *max*)**

Attaches to a *pin* a servo expecting a pulse width range between *min* and *max*.

**void detach()**

Stops the PWM signal of an attached servo.

**void moveTo(int *target*)**

Moves the servo shaft to a specific *target* position at default speed.

**void moveTo(int *position*, int *duration*)**

Moves the servo shaft to a specific *target* position in *duration* milliseconds.


