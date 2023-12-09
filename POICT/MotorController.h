#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include "StepperMotor.h"
#include "ServoMotor.h"

class MotorController {
public:
    MotorController(StepperMotor* stepper, ServoMotor* servo);
    void controlMotors(float value);

private:
    StepperMotor* _stepper;
    ServoMotor* _servo;
};

#endif
