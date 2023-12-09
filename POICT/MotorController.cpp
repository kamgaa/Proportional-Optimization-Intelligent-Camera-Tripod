#include "MotorController.h"

MotorController::MotorController(StepperMotor* stepper, ServoMotor* servo)
    : _stepper(stepper), _servo(servo) {}

void MotorController::controlMotors(float value) {
    if (value == 0.0) {
        _stepper->initPosition();
    } else if (value <= 1.52 && value >= 1.4) {
        _stepper->move(410, LOW); // 스텝모터를 움직임 (410 스텝, 방향 LOW)
    } else if (value >= 1.6 && value <= 1.64) {
        _servo->controlAngle(value); // 서보모터 각도 제어
    }
}
