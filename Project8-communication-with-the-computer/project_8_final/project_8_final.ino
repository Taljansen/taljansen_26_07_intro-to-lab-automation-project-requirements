#include <MsTimer2.h>

// user indicates of many seconds led should be on, button turns it on
// MsTimer2 to turn light off


const int buttonPin    = 6;   // button
const int ledPin       = 4;   // LED
const int interruptPin = 2;   // jumper from pin 6; only 2 and 3 can interrupt

const unsigned long TIMER_FIX = 1;   // MsTimer2 finishes ~1 ms early (Project 6)

unsigned long onTime = 5000;         // ms; whatever the user sends; 5000 is placeholder; int is too small (i guess)

void setup() {
  Serial.begin(9600); //9600 bits per second
}

void loop() {
  if (Serial.available() > 0) { //returns a how many characters are available as a count
    String incoming = Serial.readStringUntil('\n'); // new line is stop signal

    long value = incoming.toInt(); //conversion

    if (value > 0) {
      onTime = value;
      Serial.print("I received: ");
      Serial.println(onTime);
    } else {
      Serial.println("Error: that was not a positive number");
    }
  }
}

