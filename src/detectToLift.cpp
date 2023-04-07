#include <Arduino.h>
#include <ESP32Servo.h>
#include <constantDefinition.h>

// Initialize the servo motor
Servo wingServo;

void setupDetectToLift() {
  // Configure the IR sensor pins as input
  pinMode(IN_A0, INPUT);
  pinMode(IN_A1, INPUT);

  // Attach the servo motor to the pin and set the initial pulse width
  wingServo.attach(LIFT_SERVO_PIN, 500, 2400);
  wingServo.writeMicroseconds(WING_DOWN_PAUSE_PULSE);
}

void detectAndLift() {
  int irValue1 = analogRead(IN_A0);
  int irValue2 = analogRead(IN_A1);

  if (irValue1 < BLACK_LINE_DETECT_THRESHOLD && irValue2 < BLACK_LINE_DETECT_THRESHOLD) {
    wingServo.writeMicroseconds(WING_UP_PULSE);
  } else {
    wingServo.writeMicroseconds(WING_UP_PULSE);
  }
}
