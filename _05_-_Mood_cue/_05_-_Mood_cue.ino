#include <Servo.h>

Servo myServo;

int potPin = A0;
int servoPin = 9;

int potValue;
int angle;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);
  Serial.print("Pot value: ");
  Serial.print(potValue);

  angle = map(potValue, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}
