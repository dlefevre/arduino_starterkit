const int sensorPin = A0;
float reftemp = 20;

void setup() {
  Serial.begin(9600);
  
  for(int i=2; i<5; ++i) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  pinMode(5, INPUT);
}

void setLEDs(int x, int y, int z) {
  digitalWrite(2, x);
  digitalWrite(3, y);
  digitalWrite(4, z);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorValue);

  float voltage = sensorValue / 1024.0 * 5.0;
  Serial.print(", volts: ");
  Serial.print(voltage);

  float temperature = (voltage - 0.5) * 100;
  Serial.print(", temperature: ");
  Serial.print(temperature);
  Serial.print(", ref: ");
  Serial.println(reftemp);

  if(digitalRead(5) == HIGH) {
    reftemp = temperature;
    setLEDs(HIGH, LOW, LOW);
    delay(50);
    setLEDs(LOW, HIGH, LOW);
    delay(50);
    setLEDs(LOW, LOW, HIGH);
    delay(50);
    setLEDs(LOW, LOW, LOW);
    delay(1000);
    
    return;
  }

  if(temperature < reftemp) {
    setLEDs(LOW, LOW, LOW);
  } else if (temperature >= reftemp + 2 && temperature < reftemp + 4) {
    setLEDs(HIGH, LOW, LOW);
  } else if (temperature >= reftemp + 4 && temperature < reftemp + 6) {
    setLEDs(HIGH, HIGH, LOW);
  } else if (temperature >= reftemp + 6) {
    setLEDs(HIGH, HIGH, HIGH);
  }

  delay(100);
}
