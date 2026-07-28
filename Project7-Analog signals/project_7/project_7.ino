


int rotaryPin = A0;
int rotaryValue;

void setup() {
  Serial.begin(9600);
}

void loop() {
  rotaryValue = analogRead(rotaryPin);
  Serial.println(rotaryValue);
  delay(200);
}