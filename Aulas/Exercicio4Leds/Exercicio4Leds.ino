byte pin8 = 8;
byte pin9 = 9;
byte pin10 = 10;
byte pin11 = 11;


void setup() {
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, OUTPUT);
}

void loop() {
  delay(500);
  digitalWrite(pin8,HIGH);
  delay(500);
  digitalWrite(pin8,LOW);
  delay(500);
  digitalWrite(pin9,HIGH);
  delay(500);
  digitalWrite(pin9,LOW);
  delay(500);
  digitalWrite(pin10,HIGH);
  delay(500);
  digitalWrite(pin10,LOW);
  delay(500);
  digitalWrite(pin11,HIGH);
  delay(500);
  digitalWrite(pin11,LOW);
  
  
}
