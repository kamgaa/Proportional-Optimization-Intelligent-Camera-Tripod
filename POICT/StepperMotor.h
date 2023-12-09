#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

#include <Arduino.h>

class StepperMotor {
public:
    StepperMotor(int pulPin, int dirPin, int enaPin, int buttonPin);
    void move(int steps, int direction);
    void initPosition();

private:
    int _pulPin, _dirPin, _enaPin, _buttonPin;
    void step(int direction);
};

#endif
