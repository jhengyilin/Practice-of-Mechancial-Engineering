#include <Arduino.h>
#include <ESP32Servo.h>
#include "constantDefinition.h"
#include "detectToLift.h"

// Initialize the servo motor
Servo WingServo_front, WingServo_back;

void attachAndSetServo(Servo &servo, int pin) {
  servo.setPeriodHertz(50);
  servo.attach(pin, 500, 2500);
}

void setupTwoServo() {
  // Configure the IR sensor pins as input
  attachAndSetServo(WingServo_front, LIFT_SERVO_PIN_Front);
  attachAndSetServo(WingServo_back, LIFT_SERVO_PIN_Back);
}

// sleep 5 seconds and lift 
void Lift(Servo &front, Servo &back) {
  front.write(240);
  back.write(240);
}

