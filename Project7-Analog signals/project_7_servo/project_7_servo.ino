

#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(7); //initialise pin 7
  myServo.write(90);
}

void loop() {
}