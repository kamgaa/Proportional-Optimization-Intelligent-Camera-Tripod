#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <Servo.h>

class ServoMotor {
public:
    ServoMotor(int servoPin);
    void controlAngle(float value);

private:
    Servo _myServo;
    int _currentAngle;
};

#endif
