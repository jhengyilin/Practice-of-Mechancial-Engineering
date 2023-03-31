#include <Arduino.h>
#include <ESP32Servo.h>

// Pins for servo motors
const int frontRightPin = 33;
const int frontLeftPin = 32;
const int backRightPin = 22;
const int backLeftPin = 23;

// Servo objects
Servo frontRight;
Servo frontLeft;
Servo backRight;
Servo backLeft;

// Function declarations
void moveForward(int pulseWidth);
void moveBackward(int pulseWidth);
void turnRight(int pulseWidth);
void turnLeft(int pulseWidth);
void pause_motor();

void attachAndSetServo(Servo &servo, int pin) {
  servo.setPeriodHertz(50);
  servo.attach(pin, 500, 2400);
}

void setup() {
  Serial.begin(115200);

  // Attach servos and set their frequency
  attachAndSetServo(frontRight, frontRightPin);
  attachAndSetServo(frontLeft, frontLeftPin);
  attachAndSetServo(backRight, backRightPin);
  attachAndSetServo(backLeft, backLeftPin);
}

void loop() {
  Serial.println("Moving forward:");
  moveForward(2000);
  delay(2000);

  Serial.println("Pausing for 2 seconds.");
  pause_motor();
  delay(2000);
  
    Serial.println("Moving backward:");
  moveBackward(1000);
  delay(2000);

  Serial.println("Pausing for 2 seconds.");
  pause_motor();
  delay(2000);

  Serial.println("Turning right:");
  turnRight(500);
  delay(2000);

  Serial.println("Pausing for 2 seconds.");
  pause_motor();
  delay(2000);

  Serial.println("Turning left:");
  turnLeft(500);
  delay(2000);

  Serial.println("Pausing for 2 seconds.");
  pause_motor();
  delay(2000);
  

}

void pause_motor() {
  int pulseWidth = 1500;
  frontRight.writeMicroseconds(pulseWidth);
  frontLeft.writeMicroseconds(pulseWidth);
  backRight.writeMicroseconds(pulseWidth);
  backLeft.writeMicroseconds(pulseWidth);
}

void moveForward(int pulseWidth) {
  frontRight.writeMicroseconds(pulseWidth);
  frontLeft.writeMicroseconds(pulseWidth);
  backRight.writeMicroseconds(pulseWidth);
  backLeft.writeMicroseconds(pulseWidth);
}

void moveBackward(int pulseWidth) {
  frontRight.writeMicroseconds(pulseWidth);
  frontLeft.writeMicroseconds(pulseWidth);
  backRight.writeMicroseconds(pulseWidth);
  backLeft.writeMicroseconds(pulseWidth);
}

void turnRight(int pulseWidth) {
  frontRight.writeMicroseconds(1500 - pulseWidth);
  frontLeft.writeMicroseconds(1500 + pulseWidth);
  backRight.writeMicroseconds(1500 - pulseWidth);
  backLeft.writeMicroseconds(1500 + pulseWidth);
}


void turnLeft(int pulseWidth) {
  frontRight.writeMicroseconds(1500 + pulseWidth);
  frontLeft.writeMicroseconds(1500 - pulseWidth);
  backRight.writeMicroseconds(1500 + pulseWidth);
  backLeft.writeMicroseconds(1500 - pulseWidth);
}
