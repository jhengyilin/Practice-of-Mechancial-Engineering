#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <ESP32Servo.h>
#include <Arduino.h>
#include <constantDefinition.h>

class FourWheel : public Servo{
    public:
        FourWheel(int pulseWidth); // constructor

        // Function declarations
        void moveForward(int pulseWidth);
        void moveBackward(int pulseWidth);
        void turnRight(int pulseWidth);
        void turnLeft(int pulseWidth);
        void pause_motor();
        void attachAndSetServo(Servo &servo, int pin);

    private:
        int pulseWidth;
        Servo frontRight;
        Servo frontLeft;
        Servo backRight;
        Servo backLeft;
};


FourWheel::FourWheel(int pulseWidth) {
    this->pulseWidth = pulseWidth;

    // Attach servos and set their frequency
    attachAndSetServo(frontRight, frontRightPin);
    attachAndSetServo(frontLeft, frontLeftPin);
    attachAndSetServo(backRight, backRightPin);
    attachAndSetServo(backLeft, backLeftPin);
}

#endif // MOTORCONTROL_H
