#include <Arduino.h>

// Motor A (L298N 1)
const int motorA1 = 27; // IN1
const int motorA2 = 26; // IN2
const int motorAPWM = 25; // ENA

// Motor B (L298N 1)
const int motorB1 = 14; // IN3
const int motorB2 = 12; // IN4
const int motorBPWM = 13; // ENB

// Motor C (L298N 2)
const int motorC1 = 33; // IN1
const int motorC2 = 32; // IN2
const int motorCPWM = 15; // ENA

// Motor D (L298N 2)
const int motorD1 = 18; // IN3
const int motorD2 = 19; // IN4
const int motorDPWM = 21; // ENB

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorAPWM, OUTPUT);

  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorBPWM, OUTPUT);

  pinMode(motorC1, OUTPUT);
  pinMode(motorC2, OUTPUT);
  pinMode(motorCPWM, OUTPUT);

  pinMode(motorD1, OUTPUT);
  pinMode(motorD2, OUTPUT);
  pinMode(motorDPWM, OUTPUT);
}

void loop() {
  // Set motor speed and direction
  controlMotor(motorA1, motorA2, motorAPWM, 255, true);
  controlMotor(motorB1, motorB2, motorBPWM, 255, true);
  controlMotor(motorC1, motorC2, motorCPWM, 255, true);
  controlMotor(motorD1, motorD2, motorDPWM, 255, true);

  delay(2000); // Run motors for 2 seconds

  // Stop motors
  controlMotor(motorA1, motorA2, motorAPWM, 0, true);
  controlMotor(motorB1, motorB2, motorBPWM, 0, true);
  controlMotor(motorC1, motorC2, motorCPWM, 0, true);
  controlMotor(motorD1, motorD2, motorDPWM, 0, true);

  delay(2000); // Stop for 2 seconds
}

void controlMotor(int motorPin1, int motorPin2, int motorPWM, int speed, bool direction) {
  digitalWrite(motorPin1, direction);
  digitalWrite(motorPin2, !direction);
  analogWrite(motorPWM, speed);
}
