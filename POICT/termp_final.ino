#include "StepperMotor.h"
#include "ServoMotor.h"
#include "MotorController.h"
#include "SerialCommunication.h"

const float desiredValue = 1.62;
const int buttonPin = 2;
const int PUL = 7;
const int DIR = 6;
const int ENA = 5;
const int servoPin = 3;

StepperMotor stepperMotor(PUL, DIR, ENA, buttonPin);
ServoMotor servoMotor(servoPin);
MotorController motorController(&stepperMotor, &servoMotor);
SerialCommunication serialComm(desiredValue);

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5000);
}

void loop() {
  float receivedValue = serialComm.getReceivedValue();
  motorController.controlMotors(receivedValue);
}
