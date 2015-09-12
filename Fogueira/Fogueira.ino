const byte ledVermelho = 10;
const byte ledAmarelo1 = 9;
const byte ledAmarelo2 = 11;

void setup() {
  pinMode(ledVermelho,OUTPUT);
  pinMode(ledAmarelo1,OUTPUT);
  pinMode(ledAmarelo2,OUTPUT);
}

void loop() {
  analogWrite(ledVermelho,random(120)+136);
  analogWrite(ledAmarelo1,random(120)+136);
  analogWrite(ledAmarelo2,random(120)+136);
  delay(random(100));
}
