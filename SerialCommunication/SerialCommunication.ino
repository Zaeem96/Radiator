#include <Motor.h>

// Initialize motor on digital pin 8,9,10,11
Motor motor(8, 9, 10, 11);
// Initialize temperature sensor on analog pin 0
const int sensorPin = A0;
// Motor must maximum travel 5mm, 1mm == 512 steps.
const int motorMaxPosition = 2560 / 2;
// Since the 28BYJ48 motor has a gear ratio of 64, and a stride angle of 5.625, (360/5.625)*(64/8) = 512;
const int oneRound = 512;
const int halfRound = 256;
int motorPosition;
float targetTemperature = 20;
float currentTemperature;

const byte numChars = 32;
char receivedChars[numChars]; // an array to store the received data

boolean newData = false;

void setup() {
  Serial.begin(9600);
  motorPosition = 0;
}

void loop() {
  
  setCurrentTemperature();
 
  recvData();
  // Try to update the motorPosition
  updatePosition();
  // Sleep 15 seconds, before checking temperature again.
  // In real world it should be 5-10 minutes, for better battery performance.
  delay(15000);
}

// Updates motorPosition
void updatePosition() {
  Serial.println("------------------------------------------------");
  Serial.println("currentTemperature:" +String(currentTemperature));
  Serial.println("targetTemperature:" + String(targetTemperature));
  Serial.println("Boundaries:"+String(checkTemperatureBoundaries()));
  if (checkTemperatureBoundaries()) {
    // turn the heat up
    Serial.println("position:" + String(motorPosition));
    if (targetTemperature > currentTemperature && motorPosition < motorMaxPosition) {
      Serial.println("up");
      motor.counterclockwise(halfRound);
      motorPosition += halfRound;
      // turn it down
    } else if (targetTemperature < currentTemperature && motorPosition > 0) {
      Serial.println("down");
      motor.clockwise(halfRound);
      motorPosition -= halfRound;
    }
  }
}

// Checks if target temperature is within 2 degrees range of currentTemperature
boolean checkTemperatureBoundaries() {
  return !(targetTemperature > currentTemperature - 1 && targetTemperature < currentTemperature + 1);
}

// Read current temperature from arduino
float setCurrentTemperature() {
  // Read voltage on sensor
  float voltage = (analogRead(sensorPin) / 1024.0) * 5.0;
  // Convert to temperature
  currentTemperature = (voltage - .5) * 100;
  // Print/Send temperature on serial
  Serial.println(currentTemperature);
}

 // If something is sent on the usb bus, read it and update temp.
void recvData() {
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;
  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();
    if (rc != endMarker) {
      receivedChars[ndx] = rc;
      ndx++;
      if (ndx >= numChars) {
        ndx = numChars - 1;
      }
    }
    else {
      receivedChars[ndx] = '\0'; // terminate the string
      ndx = 0;
      newData = true;
    }
  }
    if (newData == true) {
    targetTemperature = atof(receivedChars);
    newData = false;
  }
  if (Serial.available() > 0) {
    recvData();
  }
}


