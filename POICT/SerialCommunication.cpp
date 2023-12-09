#include "SerialCommunication.h"

SerialCommunication::SerialCommunication(float desiredValue)
    : _desiredValue(desiredValue), _errorValue(0.0) {}

float SerialCommunication::getReceivedValue() {
    float receivedValue = -1;

    if (Serial.available() > 0) {
        receivedValue = Serial.parseFloat();
        if (receivedValue != 0.0 || Serial.peek() == '\n') {
            _errorValue = _desiredValue - receivedValue;
            Serial.print("Received Value: ");
            Serial.println(receivedValue);
            Serial.print("Error: ");
            Serial.println(_errorValue);
        } else {
            receivedValue = -1;
        }
    }
    return receivedValue;
}
