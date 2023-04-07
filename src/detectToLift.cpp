#include <Arduino.h>
#include <ESP32Servo.h>
#include "constantDefinition.h"
#include "detectToLift.h"

// Initialize the servo motor
Servo WingServo;

void setupDetectToLift() {
  // Configure the IR sensor pins as input
  pinMode(IN_A0, INPUT);
  pinMode(IN_A1, INPUT);

  // Attach the servo motor to the pin and set the initial pulse width
  WingServo.attach(LIFT_SERVO_PIN, 500, 2400);
  WingServo.writeMicroseconds(WING_DOWN_PAUSE_PULSE);
}

void detectAndLift() {
  int irValue1 = analogRead(IN_A0);
  int irValue2 = analogRead(IN_A1);

  if (irValue1 < BLACK_LINE_DETECT_THRESHOLD && irValue2 < BLACK_LINE_DETECT_THRESHOLD) {
    WingServo.writeMicroseconds(WING_UP_PULSE);
  } else {
    WingServo.writeMicroseconds(WING_UP_PULSE);
  }
}
