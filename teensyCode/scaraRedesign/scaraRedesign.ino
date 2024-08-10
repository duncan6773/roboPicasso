#include "stepMotorManager.h"
#include "stepMotorClass.h" 
/*
80 ms is the fastest you can push these motors 
*/


int motor1Speed = 200; //80 is our limit 
stepMotorClass heightMotor(40,41);
stepMotorClass joint2Motor(37,38);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // setupMotors();
  // digitalWrite(dirPin1, HIGH);
  // motor1Timer.begin(moveMotorOne, motor1Speed);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(dirPin2, LOW);
  heightMotor.setVelocity(100, true);
  joint2Motor.setVelocity(100, true);
  delay(3000);
  heightMotor.setVelocity(100, false);
  joint2Motor.setVelocity(100, false);
  // digitalWrite(dirPin2, HIGH);
  delay(3000);
  // motor1Speed = motor1Speed -5;
  // if(motor1Speed <= 0){
  //   motor1Speed = 100;
  // }
  // Serial.print("Motor 1 Speed:  ");
  // Serial.println(motor1Speed);
  // motor1Timer.update(motor1Speed);
  

}


