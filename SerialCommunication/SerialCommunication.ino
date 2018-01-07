#include <Motor.h>

Motor motor(8, 9, 10, 11);
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
 
  
}
void loop() {
 // motor.update();
  //if (Serial.available()) { 
   // motor.setMotorDirection(readData());
  //}
  float temp = checkTemperature(analogRead(sensorPin));
  
  if(temp
  delay(1000);
}

int readData() {
  String decimal1 = String(Serial.read() - '0');
  String decimal2 = String(Serial.read() - '0');
  return (decimal1 + decimal2).toInt();
}

float checkTemperature(int sensorVal) {
  float voltage = sensorVal * (5000/1024);
  Serial.println((voltage-500)/10);
  return (voltage - 500) / 10;
}


