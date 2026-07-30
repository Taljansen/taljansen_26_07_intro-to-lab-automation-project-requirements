

void setup() {
  Serial.begin(9600);
  pinMode(6, INPUT);
}

void loop() {
  Serial.println(digitalRead(6));
  delay(200);
}