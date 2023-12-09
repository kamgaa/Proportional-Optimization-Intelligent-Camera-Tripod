#include "StepperMotor.h"

StepperMotor::StepperMotor(int pulPin, int dirPin, int enaPin, int buttonPin)
    : _pulPin(pulPin), _dirPin(dirPin), _enaPin(enaPin), _buttonPin(buttonPin) {
    pinMode(_dirPin, OUTPUT);
    pinMode(_enaPin, OUTPUT);
    pinMode(_pulPin, OUTPUT);
    pinMode(_buttonPin, INPUT_PULLUP);
}

void StepperMotor::move(int steps, int direction) {
    for (int i = 0; i < steps; i++) {
        step(direction);
    }
}

void StepperMotor::initPosition() {
    while (digitalRead(_buttonPin) == HIGH) {
        step(HIGH); // 모터를 위 방향으로 설정
    }

    for (int i = 0; i < 50; i++) { // 50 스텝 정도 내려오는 것을 예시로 설정
        step(LOW); // 모터를 아래 방향으로 설정
    }
    
}

void StepperMotor::step(int direction) {
    digitalWrite(_dirPin, direction);
    digitalWrite(_enaPin, HIGH);
    digitalWrite(_pulPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(_pulPin, LOW);
    delayMicroseconds(1000);
}
