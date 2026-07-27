

int buttonPin = 6;
int ledPin = 4;
int lastState = LOW;  
int interruptPin = 2;
volatile bool ledState = false;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), buttonISR, CHANGE);
}

void loop() {
  for (int i = 0; i < 10000; i++) {
    Serial.println("calculating...");
  }

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