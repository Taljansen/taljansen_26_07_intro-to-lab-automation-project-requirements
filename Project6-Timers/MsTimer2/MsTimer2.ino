#include <MsTimer2.h>

int buttonPin = 6;
int ledPin = 4;
int interruptPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(interruptPin, INPUT);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), buttonISR, RISING);
  MsTimer2::set(5000, ledOff);   // after 5000 ms, call ledOff
}

void loop() {
  volatile long dummy = 0;
  long i = 0;
  for (i = 0; i < 2000000; i++) {
    dummy = dummy + 1;
  }
  Serial.print("dummy: ");
  Serial.println(dummy);
}

void buttonISR() {
  digitalWrite(ledPin, HIGH);
  MsTimer2::start();
}

void ledOff() {
  digitalWrite(ledPin, LOW);
  MsTimer2::stop();   // stop, or it would fire again every 5 s
}