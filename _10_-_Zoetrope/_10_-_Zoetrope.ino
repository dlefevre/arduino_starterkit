const int ctrlPin1 = 2;
const int ctrlPin2 = 3;
const int onOffSwitchPin = 4;
const int directionSwitchPin = 5;
const int enablePin = 9;
const int potPin = A0;

int onOffSwitchState = LOW;
int prevOnOffSwitchState = LOW;
int directionSwitchState = LOW;
int prevDirectionSwitchState = LOW;

int motorSpeed = 0;
bool motorEnabled = false;
bool motorReversed = false;

void setup() {
  pinMode(ctrlPin1, OUTPUT);
  pinMode(ctrlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(onOffSwitchPin, INPUT);
  pinMode(directionSwitchPin, INPUT);

  digitalWrite(enablePin, LOW);
  Serial.begin(9600);
}

void loop() {
  // on/off switch
  onOffSwitchState = digitalRead(onOffSwitchPin);
  if(onOffSwitchState != prevOnOffSwitchState && onOffSwitchState == HIGH) {
    motorEnabled = !motorEnabled;
  }
  prevOnOffSwitchState = onOffSwitchState;

  // Direction switch
  directionSwitchState = digitalRead(directionSwitchPin);
  if(directionSwitchState != prevDirectionSwitchState && directionSwitchState == HIGH) {
    motorReversed = !motorReversed;
  }
  prevDirectionSwitchState = directionSwitchState;

  // Speed
  motorSpeed = analogRead(potPin) / 4;
  Serial.println(motorSpeed);

  // Steer motor
  digitalWrite(ctrlPin1, motorReversed ? LOW : HIGH);
  digitalWrite(ctrlPin2, motorReversed ? HIGH : LOW);
  analogWrite(enablePin, motorEnabled ? motorSpeed : 0);
}
