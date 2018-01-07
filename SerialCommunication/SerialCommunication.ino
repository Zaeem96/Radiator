#include <Motor.h>

// Initialize motor on digital pin 8,9,10,11
Motor motor(8, 9, 10, 11);
// Initialize temperature sensor on analog pin 0
const int sensorPin = A0;
// Motor must maximum travel 5mm, 1mm == 512 steps.
const int motorMaxPosition = 2560;
// Since the 28BYJ48 motor has a gear ratio of 64, and a stride angle of 5.625, (360/5.625)*(64/8) = 512;
const int oneRound = 512;
int motorPosition;
float targetTemperature = 20;
float currentTemperature;

void setup() {
  Serial.begin(9600);
  motorPosition = 0;
  // Wait 2 seconds, to make sure everything is initialized.
  delay(2000);
}

void loop() {
  // Read current temperature from arduino
  setCurrentTemperature();
  // If something is sent on the usb bus, read it and update temp.
  if (Serial.available()) {
    // Read the recieved data, and convert it to float
    targetTemperature = Serial.readString().toFloat();
  }
  // Try to update the motorPosition
  updatePosition();
  // Sleep 30 seconds, before checking temperature again.
  // In real world it should be 5-10 minutes, for better battery performance.
  delay(30000);
}

// Updates motorPosition
void updatePosition() {
  if (checkTemperatureBoundaries) {
    if (targetTemperature > currentTemperature && motorPosition < motorMaxPosition) {
      motor.counterclockwise(oneRound);
      motorPosition += oneRound;
    } else if (targetTemperature < currentTemperature && motorPosition > 0) {
      motor.clockwise(oneRound);
      motorPosition -= oneRound;
    }
  }
}

// Checks if target temperature is within 2 degrees range of currentTemperature
boolean checkTemperatureBoundaries() {
  return targetTemperature > currentTemperature - 1 && targetTemperature < currentTemperature + 1;
}

float setCurrentTemperature() {
  // Read voltage on sensor
  float voltage = (analogRead(sensorPin) / 1024.0) * 5.0;
  // Convert to temperature
  currentTemperature = (voltage - .5) * 100;
  // Print/Send temperature on serial
  Serial.println(currentTemperature);
}


