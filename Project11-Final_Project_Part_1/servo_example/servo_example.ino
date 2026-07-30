#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
int fanPin = 7;  // set D6 as control switch 
int fanState = LOW;

void setup() {
    Serial.begin(9600);
    myservo.attach(3);  // attaches the servo on pin 2 to the servo object
    pinMode(fanPin, OUTPUT);
}
 
void loop() {

 fanState = HIGH;
 digitalWrite(fanPin, fanState);

   for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 100 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(40);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 100; pos >= 0; pos -= 1) { // goes from 100 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(40);                       // waits 15ms for the servo to reach the position
  }
}