#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <Arduino.h>

class SerialCommunication {
public:
    SerialCommunication(float desiredValue);
    float getReceivedValue();

private:
    float _desiredValue;
    float _errorValue;
};

#endif
