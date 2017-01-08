const int switchPin = 8;
int switchState = 0;
int prevSwitchState = 0;

unsigned long previousTime = 0;
int led = 2;
bool flash = false;

void setup() {
  for(int i=2; i<8; ++i) {
    pinMode(i, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState) {
    prevSwitchState = switchState;
    led = 2;
    for(int i=2; i<8; ++i) {
      digitalWrite(i, LOW);
      flash = false;
    }
  }

  if(flash) {
    int setTo;
    if(digitalRead(7) == HIGH) {
      setTo = LOW;
    } else {
      setTo = HIGH;
    }
    for(int i=2; i<8; ++i) {
      digitalWrite(i, setTo);
    }
    delay(100);
    return;
  }
  
  unsigned long currentTime = millis();

  if(currentTime - previousTime > 2000) {
    previousTime = currentTime;
    if(led > 7) {
      delay(1000);
      flash = true;
    } else {
      digitalWrite(led++, HIGH);
    }
  }
}
