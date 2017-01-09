#include <Servo.h>

Servo myServo;

const int piezoPin = A0;
const int switchPin = 2;
const int yellowLedPin = 3;
const int greenLedPin = 4;
const int redLedPin = 5;

const int quietKnock = 50;
const int loudKnock = 300;

bool locked = false;
int numberOfKnocks = 0;

void setup() {
  myServo.attach(9);
 
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(switchPin, INPUT);

  Serial.begin(9600);

  digitalWrite(greenLedPin, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked");
}

bool checkForKnockValue(int knockValue) {
  Serial.print("Knock value: ");
  Serial.print(knockValue);

  if(knockValue >= quietKnock && knockValue <= loudKnock) {
    digitalWrite(yellowLedPin, HIGH);
    Serial.println(" -> valid");
    delay(50);
    digitalWrite(yellowLedPin, LOW);
    return true;
  } else {
    Serial.println(" -> invalid");
    return false;
  }
}

void loop() {
  if(locked == false) {
    int switchVal = digitalRead(switchPin);
    if(switchVal == HIGH) {
      locked = true;
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
      myServo.write(90);
      delay(1000);
    }
  } else {
    int knockVal = analogRead(piezoPin);
    if(numberOfKnocks < 3 && knockVal > 0) {
      if(checkForKnockValue(knockVal)) {
        ++numberOfKnocks;
        delay(100);
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go");
    }
    if(numberOfKnocks >= 3 ) {
      locked = false;
      numberOfKnocks = 0;d
      myServo.write(0);
      delay(20);
      digitalWrite(greenLedPin, HIGH);
      digitalWrite(redLedPin, LOW);
      Serial.println("the box is unlocked");
    }
  }
}
