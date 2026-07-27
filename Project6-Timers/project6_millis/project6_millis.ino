
// millis() Returns the number of milliseconds passed since the Arduino board began running the current program. 
// This number will overflow (go back to zero), after approximately 50 days.

int buttonPin = 6;
int ledPin = 4;
int interruptPin = 2;
unsigned long myTime;
unsigned long buttonPresssed;

void setup() {
  Serial.begin(9600);
  pinMode(interruptPin, INPUT);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), buttonISR, RISING);
// rising = press only, falling = release only, change - both directions: LOW→HIGH (press) and HIGH→LOW (release)

}

void loop() {
  Serial.print("Time: ");
  myTime = millis();

  Serial.println(myTime); // prints time since program started

  if (myTime - buttonPresssed >= 5000){
      digitalWrite(ledPin, LOW);
  } 
    
// pauses for 5 seconds
// time does NOT WORK inside interrupt functions
}

void buttonISR() {
  digitalWrite(ledPin, HIGH);
  buttonPresssed = millis();
  }