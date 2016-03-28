byte pin6 = 6;
int i;

void setup() {
}

void loop() {
  for(i = 0; i <= 100; i ++){
    analogWrite(pin6,i);
    delay(25);
  }
}
