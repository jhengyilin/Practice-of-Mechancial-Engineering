#include <Arduino.h>
#include <ESP32Servo.h>
#include "constantDefinition.h"
#include "detectToLift.h"
#include "motorControl.h"

void line_tracking(int analog_0, int analog_1, int analog_2, int analog_3, FourWheel *car){
    int* value_A0 = new int;
    int* value_A1 = new int;
    int* value_A2 = new int;
    int* value_A3 = new int;
    *value_A0 = analogRead(IN_A0); 
    *value_A1 = analogRead(IN_A1);
    *value_A2 = analogRead(IN_A2);
    *value_A3 = analogRead(IN_A3);
    // extreme condition 
    if (analog_0 > BLACK_LINE_DETECT_THRESHOLD){
        // move drastically until number 2 touches the line 
        while (*value_A2 < BLACK_LINE_DETECT_THRESHOLD){
            car->turnLeft(200);
            delay(20);
            *value_A2 = analogRead(IN_A2);
        }
    }
    // if the right most touches the blackline 
    if (analog_3 > BLACK_LINE_DETECT_THRESHOLD){
        while (*value_A1 < BLACK_LINE_DETECT_THRESHOLD){
            car->turnRight(200);
            delay(20);
            *value_A1 = analogRead(IN_A1);
        }
    }

    // normal condition 
    if (analog_1 > BLACK_LINE_DETECT_THRESHOLD && analog_2 > BLACK_LINE_DETECT_THRESHOLD){
        car->moveForward(200);
        delay(200);
    }
    else if (analog_1 > BLACK_LINE_DETECT_THRESHOLD){ // the left touches the blackline
        // turn left 
        car->turnLeft(100);
        delay(50);
    }
    else if (analog_2 > BLACK_LINE_DETECT_THRESHOLD){ // the right touches blackline
        // turn right 
        car->turnRight(100);
        delay(50);
    }
    else{
        car->moveForward(200);
        delay(200);
    }
    delete value_A0;
    delete value_A1;
    delete value_A2;
    delete value_A3;
}