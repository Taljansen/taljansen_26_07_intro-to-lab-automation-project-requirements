// Project 8 — stage B: the PC sets the ON time, the button lights the LED,
// MsTimer2 turns it off.

#include <MsTimer2.h>

const int buttonPin    = 6;   // Grove button, wired on the shield
const int ledPin       = 4;   // Grove LED, wired on the shield
const int interruptPin = 2;   // jumper from pin 6 — only 2 and 3 can interrupt

const unsigned long TIMER_FIX = 1;   // MsTimer2 finishes ~1 ms early (Project 6)

unsigned long onTime = 5000;         // ms; replaced by whatever the PC sends

// Set inside interrupts, read in loop(). Never print from an interrupt.
volatile bool reportPress   = false;
volatile bool reportRelease = false;
volatile bool reportOff     = false;

// ---------- interrupt: the button changed state ----------
void buttonISR() {
  if (digitalRead(interruptPin) == HIGH) {   // pressed
    digitalWrite(ledPin, HIGH);
    MsTimer2::start();                       // start counting onTime
    reportPress = true;
  } else {                                   // released
    reportRelease = true;
  }
}

// ---------- timer callback: the time is up ----------
void turn_off() {
  digitalWrite(ledPin, LOW);
  MsTimer2::stop();      // MsTimer2 repeats forever unless you stop it
  reportOff = true;
}

void setup() {
  Serial.begin(9600);

  pinMode(buttonPin,    INPUT);
  pinMode(interruptPin, INPUT);
  pinMode(ledPin,       OUTPUT);
  digitalWrite(ledPin, LOW);

  MsTimer2::set(onTime + TIMER_FIX, turn_off);
  attachInterrupt(digitalPinToInterrupt(interruptPin), buttonISR, CHANGE);
}

void loop() {
  // --- 1. did the PC send a new time? ---
  if (Serial.available() > 0) {
    String incoming = Serial.readStringUntil('\n');
    incoming.trim();
    long value = incoming.toInt();       // returns 0 if it isn't a number

    if (value > 0) {
      onTime = value;
      MsTimer2::set(onTime + TIMER_FIX, turn_off);   // re-arm with the new time
      Serial.print("I received: ");
      Serial.println(onTime);
    } else {
      Serial.print("Error: expected a positive number, got '");
      Serial.print(incoming);
      Serial.println("'");
    }
  }

  // --- 2. report whatever the interrupts flagged ---
  if (reportPress)   { reportPress   = false; Serial.println("button pressed"); }
  if (reportRelease) { reportRelease = false; Serial.println("button released"); }
  if (reportOff)     { reportOff     = false; Serial.println("LED off"); }
}