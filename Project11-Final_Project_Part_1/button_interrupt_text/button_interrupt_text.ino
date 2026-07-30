

volatile int buttonState = 0;
volatile bool changed = false;

void onChange() {
  buttonState = digitalRead(2);
  changed = true;
}

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(6, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), onChange, CHANGE);
}

void loop() {
  if (changed) {
    changed = false;
    Serial.print("state: ");
    Serial.println(buttonState);
  }
}