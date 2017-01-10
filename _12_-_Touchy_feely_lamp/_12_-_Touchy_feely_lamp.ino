#include <CapacitiveSensor.h>

CapacitiveSensor cs = CapacitiveSensor(4, 2);
int threshold = 500;
const int ledPin = 12;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long sensorValue = cs.capacitiveSensor(30);
  Serial.println(sensorValue);
  digitalWrite(ledPin, sensorValue > threshold ? HIGH : LOW);
  delay(10);
}
