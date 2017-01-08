int value = 0;
int minValue = 1023;
int maxValue = 0;

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  while(millis() < 5000) {
    value = analogRead(A0);

    if(value < minValue) 
      minValue = value;
    if(value > maxValue)
      maxValue = value;
  }

  digitalWrite(13, LOW);
}

void loop() {
  value = analogRead(A0);
  int pitch = map(value, minValue, maxValue, 50, 4000);
  tone(8, pitch, 15);
  delay(10);
}
