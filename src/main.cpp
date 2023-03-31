#include <Arduino.h>
#include <ESP32Servo.h>

// Pins for servo motors
const int frontRightPin = 33;
const int frontLeftPin = 32;
const int backRightPin = 22;
const int backLeftPin = 23;
// Pins for IR sensors
// The ADC driver API supports ADC1 (8 channels, attached to GPIOs 32 - 39)
// and ADC2 (10 channels, attached to GPIOs 0, 2, 4, 12 - 15 and 25 - 27)
const int IN_A0 = 19; // analog input
const int IN_D0 = 18; // digital input

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

  pinMode (IN_A0, INPUT);
  pinMode (IN_D0, INPUT);
}


int value_A0;
bool value_D0;

void loop() {

  value_A0 = analogRead(IN_A0); // reads the analog input from the IR distance sensor
  value_D0 = digitalRead(IN_D0);// reads the digital input from the IR distance sensor

  Serial.println("Moving backward:");
  moveBackward(500);
  delay(2000);

  Serial.println("Pausing for 2 seconds.");
  pause_motor();
  delay(2000);  
  
  
  Serial.println("Moving forward:");
  moveForward(1000);
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
  frontRight.writeMicroseconds(1500 + pulseWidth);
  frontLeft.writeMicroseconds(1500 - pulseWidth);
  backRight.writeMicroseconds(1500 + pulseWidth);
  backLeft.writeMicroseconds(1500 - pulseWidth);
}

void moveBackward(int pulseWidth) {
  frontRight.writeMicroseconds(1500 - pulseWidth);
  frontLeft.writeMicroseconds(1500 + pulseWidth);
  backRight.writeMicroseconds(1500 - pulseWidth);
  backLeft.writeMicroseconds(1500 + pulseWidth);
}

void turnRight(int pulseWidth) {
  frontRight.writeMicroseconds(1500 + pulseWidth);
  frontLeft.writeMicroseconds(1500 + pulseWidth);
  backRight.writeMicroseconds(1500 + pulseWidth);
  backLeft.writeMicroseconds(1500 + pulseWidth);
}


void turnLeft(int pulseWidth) {
  frontRight.writeMicroseconds(1500 - pulseWidth);
  frontLeft.writeMicroseconds(1500 - pulseWidth);
  backRight.writeMicroseconds(1500 - pulseWidth);
  backLeft.writeMicroseconds(1500 - pulseWidth);
}
