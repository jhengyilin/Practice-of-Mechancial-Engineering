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
        void setup();

    private:
        int pulseWidth;
        Servo frontRight;
        Servo frontLeft;
        Servo backRight;
        Servo backLeft;

        void attachAndSetServo(Servo &servo, int pin);
};

#endif // MOTORCONTROL_H
