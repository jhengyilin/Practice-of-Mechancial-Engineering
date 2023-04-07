#include "../include/motorControl.h"
#include <Arduino.h>
#include <ESP32Servo.h>

void FourWheel::setup() {
  // Attach servos and set their frequency
  attachAndSetServo(frontRight, frontRightPin);
  attachAndSetServo(frontLeft, frontLeftPin);
  attachAndSetServo(backRight, backRightPin);
  attachAndSetServo(backLeft, backLeftPin);
}

void FourWheel::pause_motor() {
  this->pulseWidth = 1500;
  frontRight.writeMicroseconds(pulseWidth);
  frontLeft.writeMicroseconds(pulseWidth);
  backRight.writeMicroseconds(pulseWidth);
  backLeft.writeMicroseconds(pulseWidth);
}

void FourWheel::moveForward(int pulseWidth) {
  frontRight.writeMicroseconds(1500 + pulseWidth);
  frontLeft.writeMicroseconds(1500 - pulseWidth);
  backRight.writeMicroseconds(1500 + pulseWidth);
  backLeft.writeMicroseconds(1500 - pulseWidth);
}

void FourWheel::moveBackward(int pulseWidth) {
  frontRight.writeMicroseconds(1500 - pulseWidth);
  frontLeft.writeMicroseconds(1500 + pulseWidth);
  backRight.writeMicroseconds(1500 - pulseWidth);
  backLeft.writeMicroseconds(1500 + pulseWidth);
}

void FourWheel::turnRight(int pulseWidth) {
  frontRight.writeMicroseconds(1500 + pulseWidth);
  frontLeft.writeMicroseconds(1500 + pulseWidth);
  backRight.writeMicroseconds(1500 + pulseWidth);
  backLeft.writeMicroseconds(1500 + pulseWidth);
}

void FourWheel::turnLeft(int pulseWidth) {
  frontRight.writeMicroseconds(1500 - pulseWidth);
  frontLeft.writeMicroseconds(1500 - pulseWidth);
  backRight.writeMicroseconds(1500 - pulseWidth);
  backLeft.writeMicroseconds(1500 - pulseWidth);
}

void FourWheel::attachAndSetServo(Servo &servo, int pin) {
  servo.setPeriodHertz(50);
  servo.attach(pin, 500, 2400);
}
