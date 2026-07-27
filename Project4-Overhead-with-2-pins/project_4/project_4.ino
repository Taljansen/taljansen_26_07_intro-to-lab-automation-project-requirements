





int ledPin1 = 13;
int ledPin2 = 12;
int delayTime = 1;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  delay(delayTime);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  delay(delayTime);
}