// accel_servo_oled - tilt steers the fan, angle shown on OLED
// Layer 2 of the final project: accelerometer -> servo -> OLED

#include <Servo.h>
#include "Arduino_SensorKit.h"

// --- pin constants (match the wiring: servo yellow on D3, fan on D7) ---
const int SERVO_PIN = 3;
const int FAN_PIN = 7;

Servo fanServo;

void setup() {
  Serial.begin(9600);          // serial line to the computer
  Accelerometer.begin();       // wake the tilt sensor (I2C)
  fanServo.attach(SERVO_PIN);  // servo listens on pin 3

  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, HIGH); // fan on (set LOW while testing if you want quiet)

  // wake the screen, load the character dictionary
  Oled.begin();
  Oled.setFlipMode(true);      // flip to false if text is upside down for you
  Oled.setFont(u8x8_font_chroma48medium8_r);
}

void loop() {
  // 1. read tilt: roughly -1 .. +1
  float x = Accelerometer.readX();

  // 2. translate to servo range: -1..+1  ->  0..180
  int angle = (x + 1.0) * 90.0;
  angle = constrain(angle, 0, 180);   // safety clamp

  // 3. move the fan
  fanServo.write(angle);

  // 4. show the angle on the little screen
  Oled.setCursor(0, 0);
  Oled.print("angle: ");
  Oled.print(angle);
  Oled.print("   ");   // spaces erase leftover digits from longer numbers

  // 5. tell the computer too
  Serial.print("x: ");
  Serial.print(x);
  Serial.print("   angle: ");
  Serial.println(angle);

  delay(50);   // ~20 updates per second
}