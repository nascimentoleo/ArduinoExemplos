const int PinoPotenciometro = A0;
const int Led = 13;
int ValorPot = 0;
void setup() {
  pinMode(Led, OUTPUT);
}
void loop() {
  ValorPot = analogRead(PinoPotenciometro);
  digitalWrite(Led, HIGH);
  delay(ValorPot);
  digitalWrite(Led, LOW);
  delay(ValorPot);
}
