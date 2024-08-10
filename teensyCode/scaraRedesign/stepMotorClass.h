#ifndef STEPMOTORCLASS_H
#define STEPMOTORCLASS_H

#include "Arduino.h"
#include "IntervalTimer.h"

class stepMotorClass {
public:
    // Constructor
    stepMotorClass(int stepPin, int dirPin);

    // Public method to set velocity
    void setVelocity(int maxSpeedPercent, bool isForward);
    void setGearRatio(float gearRatio );


    float getPos();
private:
    // Private members
    float _curPos;
    float _gearRatio = 1;
    int _stepPin;
    int _dirPin;
    bool _isActive = false;

    // IntervalTimer instance for each object
    IntervalTimer motorTimer;

    // Static callback function to route to the correct instance
    static void timerCallback(stepMotorClass* motorInstance);

    // Non-static member function that actually handles the step
    void makeStep();
};

#endif
