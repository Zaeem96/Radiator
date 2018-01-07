#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor{
    public:
        Motor(int motorPin1, int motorPin2, int motorPin3, int motorPin4);                 
        void counterclockwise(int i);
        void clockwise(int i);
    private:        
        int _motorPin1;
        int _motorPin2;
        int _motorPin3;
        int _motorPin4;
        int _motorSpeed;
        int _motorDirection;
        
};

#endif