const int switchPin = 2;
const int motorPin = 9;

bool motorRunning = false;
int prevSwitchState = LOW;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  int switchState = digitalRead(switchPin);
  int potValue = analogRead(A0);
  int speed = map(potValue, 0, 1023, 0, 255);
  
  if(switchState == HIGH && prevSwitchState == LOW) {
    motorRunning = !motorRunning;
  }
  prevSwitchState = switchState;
  analogWrite(motorPin, motorRunning ? speed : 0);
}
