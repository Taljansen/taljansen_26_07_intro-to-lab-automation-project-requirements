

#include "Arduino_SensorKit.h"

void setup() {
  Serial.begin(9600);
  Accelerometer.begin();
}

void loop() {
  Serial.print("X: ");
  Serial.print(Accelerometer.readX());
  Serial.print("  Y: ");
  Serial.print(Accelerometer.readY());
  Serial.print("  Z: "); //gravity measured in units of g
  Serial.println(Accelerometer.readZ());
  delay(200);
}