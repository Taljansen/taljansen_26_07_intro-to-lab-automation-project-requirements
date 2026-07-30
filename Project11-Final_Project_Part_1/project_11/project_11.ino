

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    long ms = Serial.parseInt();
    if (ms > 0) {
      Serial.print("I received: ");
      Serial.println(ms);
    }
  }
}