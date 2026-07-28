
#include <MD_PWM.h>

// int ledPin = 4; 
MD_PWM pwmLed(4);
int rotaryPin = A0; // Input, read the knob
int rotaryValue;

// Output -- dim the Led
// pin is on 25% of the time (looks 25% bright) - called duty cycle
// library needs a number from 0 - 255 for the duty cycle. 0 means off, 255 means fully on, 128 means half.

// knob gives: 0 to 1023
// library 0 to 255 (max duty cycle)
// 1023/4  

void setup() {
  Serial.begin(9600);
  pwmLed.begin(48); //so 48Hz is just the frequency, it directly translates to freq of the period of the cycles
}

void loop() {
  rotaryValue = analogRead(rotaryPin); //analogRead(A0) gives 0 - 1023 (voltage), 2.5 V - 512; 5 V - 1023
  Serial.println(rotaryValue);
  delay(200);
  pwmLed.write(rotaryValue/4);
}