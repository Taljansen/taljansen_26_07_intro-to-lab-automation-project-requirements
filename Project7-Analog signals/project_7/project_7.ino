


int rotaryPin = A0; // Input, read the knob
int rotaryValue;

// Output -- dim the Led
// pin is on 25% of the time (looks 25% bright) - called duty cycle
// library needs a number from 0 - 255 for the duty cycle. 0 means off, 255 means fully on, 128 means half.

// knob gives: 0 to 1023
// library 0 to 255

void setup() {
  Serial.begin(9600);
}

void loop() {
  rotaryValue = analogRead(rotaryPin); //analogRead(A0) gives 0 - 1023 (voltage), 2.5 V - 512; 5 V - 1023
  Serial.println(rotaryValue);
  delay(200);
}