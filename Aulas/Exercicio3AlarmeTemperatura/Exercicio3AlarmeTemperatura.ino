byte buzzer = 12;
int temp;
int sensorTemp = A0;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(sensorTemp, INPUT);
}

void loop() {
  temp = (5 * analogRead(sensorTemp) * 100)/1024;

  if(temp > 25)
    digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
}
