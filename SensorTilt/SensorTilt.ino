const byte sensorPin = 2;
const byte led = 3;

int reading;
byte previous = LOW;

long tempo = 0;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  reading = digitalRead(sensorPin);

  if (reading == previous) {
    tempo = millis();
  }
  if ((millis() - tempo) > 50) {
    digitalWrite(led, reading);
    previous = reading;
  }
}
