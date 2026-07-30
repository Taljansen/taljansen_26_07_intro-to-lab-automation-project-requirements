#include <Servo.h>
#include "Arduino_SensorKit.h"

const int SERVO_PIN = 3;
const int FAN_PIN = 7;

Servo fanServo;

void setup() {
  Serial.begin(9600);
  Accelerometer.begin();
  fanServo.attach(SERVO_PIN);
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, HIGH);       // fan on
}a

void loop() {
  float x = Accelerometer.readX();   // tilt: about -1 .. +1
  int angle = (x + 1.0) * 90.0;      // -1..+1  ->  0..180
  angle = constrain(angle, 0, 180);  // safety clamp
  fanServo.write(angle);

  Serial.print("x: ");
  Serial.print(x);
  Serial.print("   angle: ");
  Serial.println(angle);

  delay(50);
}