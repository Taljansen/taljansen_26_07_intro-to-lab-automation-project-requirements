
#include <Servo.h>

const int SERVO_PIN = 5;   // <-- change this to your actual pin

Servo fanServo;

void setup() {
  fanServo.attach(SERVO_PIN);
}

void loop() {
  fanServo.write(0);     // one end
  delay(1000);
  fanServo.write(90);    // middle
  delay(1000);
  fanServo.write(180);   // other end
  delay(1000);
}