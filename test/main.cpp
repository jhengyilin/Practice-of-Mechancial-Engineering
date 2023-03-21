#include <Arduino.h>
#include <driver/ledc.h>

// Motor A (L298N 1)
const int motorA1 = 27; // IN1
const int motorA2 = 26; // IN2
const int motorAPWM = 25; // ENA

// Motor B (L298N 1)
const int motorB1 = 14; // IN3
const int motorB2 = 12; // IN4
const int motorBPWM = 13; // ENB

void setup() {
  // Set motor control pins as outputs
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorAPWM, OUTPUT);

  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorBPWM, OUTPUT);

  // Set PWM frequency for motor control
  ledcSetup(0, 5000, 8); // Channel 0, 5kHz frequency, 8-bit resolution
  ledcSetup(1, 5000, 8); // Channel 1, 5kHz frequency, 8-bit resolution

  // Attach PWM channels to motor PWM pins
  ledcAttachPin(motorAPWM, 0);
  ledcAttachPin(motorBPWM, 1);
}

void loop() {
  // Set motor A to rotate forward
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  ledcWrite(0, 255); // Set motor A PWM duty cycle to maximum (255)

  // Set motor B to rotate in the opposite direction
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  ledcWrite(1, 128); // Set motor B PWM duty cycle to half of maximum (128)

  delay(5000); // Wait for 5 seconds

  // Stop both motors
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  ledcWrite(0, 0);
  ledcWrite(1, 0);

  delay(5000); // Wait for 5 seconds
}
