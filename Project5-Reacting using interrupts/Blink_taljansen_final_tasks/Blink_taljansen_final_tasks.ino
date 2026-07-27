

int buttonPin = 6;
int ledPin = 4;
int lastState = LOW;  // default state at 0
int interruptPin = 2;
volatile bool ledState = false; // bool used instead of int because an LED is only ever on or off
// volatile = don't keep a copy, check the real value every time

// every pin is either HIGH or LOW
// HIGH means voltage is present (5 volts)
// LOW means 0 volts (1 and 0)

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(buttonPin, INPUT); //hole 6,  input
  pinMode(ledPin, OUTPUT); // hole 4,  output, here voltage goes out, this lights the LED
  Serial.begin(9600); // 9600 is the speed — 9600 bits per second. At 9600 bits per second = 156 seconds ≈ 2.6 minutes
  pinMode(interruptPin, INPUT); // Hole 2: also an input. wire means holes 6 and 2 now receive the identical signal from the button.
  attachInterrupt(digitalPinToInterrupt(interruptPin), buttonISR, CHANGE);
}

// ISR = interrupt service routine
// time does NOT WORK inside interrupt functions


void loop() {
  for (int i = 0; i < 10000; i++) {
    Serial.println("calculating..."); //At 9600 baud, 10000 lines takes over two minutes
  }

//the button gets looked at once every two minutes. Press-and-release takes half a second. It's gone before the board looks.
  int buttonState = digitalRead(buttonPin);
  if (buttonState != lastState) {
    Serial.print("button changed to: ");
    Serial.println(buttonState);
    lastState = buttonState;
  }
  digitalWrite(ledPin, buttonState);
}

void buttonISR() {
  ledState = digitalRead(interruptPin);
  digitalWrite(ledPin, ledState);
}
