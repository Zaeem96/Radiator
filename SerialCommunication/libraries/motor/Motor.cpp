#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int motorPin1, int motorPin2, int motorPin3, int motorPin4) {
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);

    _motorPin1 = motorPin1;
    _motorPin2 = motorPin2;
    _motorPin3 = motorPin3;
    _motorPin4 = motorPin4;

    _motorSpeed = (1 / 15 + 5);
}

void Motor::clockwise(int steps) {
    for (int i = 0; i < steps; i++) {
        // 1
        digitalWrite(_motorPin4, HIGH);
        digitalWrite(_motorPin3, LOW);
        digitalWrite(_motorPin2, LOW);
        digitalWrite(_motorPin1, LOW);
        delay(_motorSpeed);
        // 2
        digitalWrite(_motorPin4, HIGH);
        digitalWrite(_motorPin3, HIGH);
        digitalWrite(_motorPin2, LOW);
        digitalWrite(_motorPin1, LOW);
        delay(_motorSpeed);
        // 3
        digitalWrite(_motorPin4, LOW);
        digitalWrite(_motorPin3, HIGH);
        digitalWrite(_motorPin2, LOW);
        digitalWrite(_motorPin1, LOW);
        delay(_motorSpeed);
        // 4
        digitalWrite(_motorPin4, LOW);
        digitalWrite(_motorPin3, HIGH);
        digitalWrite(_motorPin2, HIGH);
        digitalWrite(_motorPin1, LOW);
        delay(_motorSpeed);
        // 5
        digitalWrite(_motorPin4, LOW);
        digitalWrite(_motorPin3, LOW);
        digitalWrite(_motorPin2, HIGH);
        digitalWrite(_motorPin1, LOW);
        delay(_motorSpeed);
        // 6
        digitalWrite(_motorPin4, LOW);
        digitalWrite(_motorPin3, LOW);
        digitalWrite(_motorPin2, HIGH);
        digitalWrite(_motorPin1, HIGH);
        delay(_motorSpeed);
        // 7
        digitalWrite(_motorPin4, LOW);
        digitalWrite(_motorPin3, LOW);
        digitalWrite(_motorPin2, LOW);
        digitalWrite(_motorPin1, HIGH);
        delay(_motorSpeed);
        // 8
        digitalWrite(_motorPin4, HIGH);
        digitalWrite(_motorPin3, LOW);
        digitalWrite(_motorPin2, LOW);
        digitalWrite(_motorPin1, HIGH);
        delay(_motorSpeed);
    }
    digitalWrite(_motorPin4, LOW);
    digitalWrite(_motorPin3, LOW);
    digitalWrite(_motorPin2, LOW);
    digitalWrite(_motorPin1, LOW);
}

void Motor::counterclockwise(int steps) {
    for (int i = 0; i < steps; i++) {
        // 1
        digitalWrite(_motorPin1, HIGH);
        digitalWrite(_motorPin2, LOW);
        digitalWrite(_motorPin3, LOW);
        digitalWrite(_motorPin4, LOW);
        delay(_motorSpeed);
        // 2
        digitalWrite(_motorPin1, HIGH);
        digitalWrite(_motorPin2, HIGH);
        digitalWrite(_motorPin3, LOW);
        digitalWrite(_motorPin4, LOW);
        delay(_motorSpeed);
        // 3
        digitalWrite(_motorPin1, LOW);
        digitalWrite(_motorPin2, HIGH);
        digitalWrite(_motorPin3, LOW);
        digitalWrite(_motorPin4, LOW);
        delay(_motorSpeed);
        // 4
        digitalWrite(_motorPin1, LOW);
        digitalWrite(_motorPin2, HIGH);
        digitalWrite(_motorPin3, HIGH);
        digitalWrite(_motorPin4, LOW);
        delay(_motorSpeed);
        // 5
        digitalWrite(_motorPin1, LOW);
        digitalWrite(_motorPin2, LOW);
        digitalWrite(_motorPin3, HIGH);
        digitalWrite(_motorPin4, LOW);
        delay(_motorSpeed);
        // 6
        digitalWrite(_motorPin1, LOW);
        digitalWrite(_motorPin2, LOW);
        digitalWrite(_motorPin3, HIGH);
        digitalWrite(_motorPin4, HIGH);
        delay(_motorSpeed);
        // 7
        digitalWrite(_motorPin1, LOW);
        digitalWrite(_motorPin2, LOW);
        digitalWrite(_motorPin3, LOW);
        digitalWrite(_motorPin4, HIGH);
        delay(_motorSpeed);
        // 8
        digitalWrite(_motorPin1, HIGH);
        digitalWrite(_motorPin2, LOW);
        digitalWrite(_motorPin3, LOW);
        digitalWrite(_motorPin4, HIGH);
        delay(_motorSpeed);
    }
    digitalWrite(_motorPin4, LOW);
    digitalWrite(_motorPin3, LOW);
    digitalWrite(_motorPin2, LOW);
    digitalWrite(_motorPin1, LOW);
}