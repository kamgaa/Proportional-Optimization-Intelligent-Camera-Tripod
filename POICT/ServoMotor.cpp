#include "ServoMotor.h"

ServoMotor::ServoMotor(int servoPin) {
    _myServo.attach(servoPin);
    _currentAngle = 0;
}

void ServoMotor::controlAngle(float value) {
  if (value >= 1.6 && value <= 1.64) {
    for (int angle = 90; angle <= 100; angle++) {
      _myServo.write(180 - angle); // 서보 모터 각도를 점진적으로 증가
      delay(20); // 각도 변경 사이의 지연시간 (20밀리초)
    }
    _currentAngle = 100; // 현재 각도를 업데이트
  } else {
    _myServo.write(90); // 그 외의 경우 서보 모터를 0도 위치로 이동
    _currentAngle = 0; // 현재 각도를 업데이트
  }
}
