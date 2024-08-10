#include "stepMotorClass.h"

stepMotorClass::stepMotorClass(int stepPin, int dirPin) {
    pinMode(stepPin, OUTPUT);
    _stepPin = stepPin;
    pinMode(dirPin, OUTPUT);
    _dirPin = dirPin;
}

void stepMotorClass::setVelocity(int maxSpeedPercent, bool isForward) {
    if (isForward) {
        digitalWrite(_dirPin, HIGH);
    } else {
        digitalWrite(_dirPin, LOW);
    }

    // Capture 'this' in the lambda function to pass the instance to the static callback
    motorTimer.begin([this]() { timerCallback(this); }, 200);
}

// Static callback function that calls the non-static makeStep method
void stepMotorClass::timerCallback(stepMotorClass* motorInstance) {
    if (motorInstance != nullptr) {
        motorInstance->makeStep();
    }
}

void stepMotorClass::makeStep() {
    // Moves the motor by a step
    if (_isActive) {
        digitalWrite(_stepPin, LOW);
        _isActive = false;
    } else {
        digitalWrite(_stepPin, HIGH);
        _isActive = true;
    }
}

void stepMotorClass::setGearRatio(float gearRatio){
  _gearRatio = gearRatio;
}

float stepMotorClass::getPos(){
  return _curPos;
}
