#include "core_pins.h"


//height or z axis 
const int stepPin1 = 40;
const int dirPin1 = 41;
volatile bool motorOneDir = false;
volatile bool motorOneActive = false;

// Arm Joint
const int stepPin2 = 37;
const int dirPin2 = 38;
volatile bool motorTwoDir = false;
volatile bool motorTwoActive = false;

// Base Joint
const int stepPin3 = 34;
const int dirPin3 = 35;
volatile bool motorThreeDir = false;
volatile bool motorThreeActive = false;

IntervalTimer motor1Timer;

void setupMotors(){
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
}

void moveMotorOne(){
  if(motorOneActive){
    digitalWrite(stepPin2,LOW);
    motorOneActive = false;
  } else {
    digitalWrite(stepPin2,HIGH);
    motorOneActive = true;
  }
  
}

