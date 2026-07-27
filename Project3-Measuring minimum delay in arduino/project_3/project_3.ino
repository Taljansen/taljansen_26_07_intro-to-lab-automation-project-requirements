


int ledPin = 4;        // Grove LED instead of the built-in LED on pin 13
int delayTime = 1;     // milliseconds

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH);   // pin 4 to 5 volts
  delayMicroseconds(1);
  // delay(delayTime);             // wait 1 ms
  digitalWrite(ledPin, LOW);    // pin 4 to 0 volts
  delayMicroseconds(1);
  // delay(delayTime);             // wait 1 ms
}