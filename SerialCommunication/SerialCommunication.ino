#include <Motor.h>

Motor motor(8, 9, 10, 11);
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
 
  
}
void loop() {
  motor.update();
  if (Serial.available()) { 
    motor.setMotorDirection(readData());
  }
  Serial.println(checkTemperature(analogRead(sensorPin)));
  delay(5000);
}

int readData() {
  String decimal1 = String(Serial.read() - '0');
  String decimal2 = String(Serial.read() - '0');
  return (decimal1 + decimal2).toInt();
}

float checkTemperature(int sensorVal) {
  float voltage = (sensorVal / 1024.0) * 5.0;
  return (voltage - .5) * 100;
}


