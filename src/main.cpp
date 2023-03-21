#include <Arduino.h>

// Motor A (L298N 1)
const int motorA1 = 27; // IN1
const int motorA2 = 26; // IN2
const int motorAPWM = 25; // ENA

// Motor B (L298N 1)
const int motorB1 = 14; // IN3
const int motorB2 = 12; // IN4
const int motorBPWM = 13; // ENB

// RSI-90 IR Sensors
const int irSensor1 = 22;
const int irSensor2 = 23;
const int irSensor3 = 4;
const int irSensor4 = 5;
const int irSensor5 = 17;

// Adjustable PWM control potentiometers
const int potA = 34;
const int potB = 35;

int sensorValues[5] = {0, 0, 0, 0, 0};

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorAPWM, OUTPUT);

  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorBPWM, OUTPUT);

  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);
  pinMode(irSensor4, INPUT);
  pinMode(irSensor5, INPUT);

  pinMode(potA, INPUT);
  pinMode(potB, INPUT);
}

void loop() {
  // Read sensor values
  sensorValues[0] = digitalRead(irSensor1);
  sensorValues[1] = digitalRead(irSensor2);
  sensorValues[2] = digitalRead(irSensor3);
  sensorValues[3] = digitalRead(irSensor4);
  sensorValues[4] = digitalRead(irSensor5);

  // Read potentiometer values and map to PWM range
  int pwmA = map(analogRead(potA), 0, 4095, 0, 255);
  int pwmB = map(analogRead(potB), 0, 4095, 0, 255);

  // Determine motor direction based on sensor values
  if (sensorValues[0] == HIGH || sensorValues[1] == HIGH) {
    // Turn left
    controlMotor(motorA1, motorA2, motorAPWM, pwmA, false);
    controlMotor(motorB1, motorB2, motorBPWM, pwmB, false);
  } else if (sensorValues[3] == HIGH || sensorValues[4] == HIGH) {
    // Turn right
    controlMotor(motorA1, motorA2, motorAPWM, pwmA, true);
    controlMotor(motorB1, motorB2, motorBPWM, pwmB, true);
  } else {
    // Move forward
    controlMotor(motorA1, motorA2, motorAPWM, pwmA, true);
    controlMotor(motorB1, motorB2, motorBPWM, pwmB, true);
  }

  delay(100); // Adjust the delay as needed for responsiveness
}

void controlMotor(int motorPin1, int motorPin2, int motorPWM, int speed, bool direction) {
  digitalWrite(motorPin1, direction);
  digitalWrite(motorPin2, !direction);
  analogWrite(motorPWM, speed);
}
