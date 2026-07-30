
#include <Servo.h>
#include "Arduino_SensorKit.h"

const int SERVO_PIN = 3;
const int FAN_PIN = 7;
const int BUZZER_PIN = 5;

const float X_MIN = -0.35;
const float X_MAX =  0.35;

const int ANGLE_MIN = 45;     // alarm below this  -> replace with YOUR measured threshold
const int ANGLE_MAX = 135;    // alarm above this  -> replace with YOUR measured threshold

Servo fanServo; // creates the servo object

void setup() {
  Serial.begin(9600);          // serial line to the computer
  Accelerometer.begin();       // tilt sensor (I2C)
  fanServo.attach(SERVO_PIN);  // servo on pin 3

  pinMode(FAN_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Oled.begin();
  Oled.setFlipMode(true);      // text orientation
  Oled.setFont(u8x8_font_chroma48medium8_r);
}

void loop() {

  // map(value, fromLow, fromHigh, toLow, toHigh)
  // output = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
  // from knob example: val = map(val, 0, 1023, 0, 180);  // scale for servo (0..180)
  //
  // with our measured range:
  // output = (x − (−0.35)) × (180 − 0) / (0.35 − (−0.35)) + 0
  //        = (x + 0.35) × 180 / 0.7
  //        = (x + 0.35) × 257.14

  float x = Accelerometer.readX();
  int angle = (x - X_MIN) * 180.0 / (X_MAX - X_MIN);   // map measured range -> 0..180
  angle = constrain(angle, 0, 180);                    // clamp tilts beyond the measured range

  bool alarm = (angle < ANGLE_MIN) || (angle > ANGLE_MAX);

  if (alarm) {
    analogWrite(BUZZER_PIN, 128);   // buzzer on (PWM ~50% duty = audible tone)
    digitalWrite(FAN_PIN, LOW);     // fan stops
  } else {
    analogWrite(BUZZER_PIN, 0);     // buzzer silent
    digitalWrite(FAN_PIN, HIGH);    // fan runs
  }

  fanServo.write(angle);

  Oled.setCursor(0, 0);
  Oled.print("angle: ");
  Oled.print(angle);
  Oled.print("   ");               // spaces erase leftover digits (180 -> 5 would show 580)
  Oled.setCursor(0, 1);
  Oled.print("buzzer: ");
  Oled.print(alarm ? "ON " : "OFF");   // trailing space erases the F of OFF

  Serial.print("x: ");
  Serial.print(x);
  Serial.print("   angle: ");
  Serial.println(angle);

  delay(50);   // ~20 updates per second

}