int temp;
int lm35 = A0;
byte ledVerde = 10;
byte ledAmarelo = 9;
byte ledVermelho = 8;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(lm35, INPUT);
}

void loop() {
  temp = (5 * analogRead(lm35) * 100)/1024;
  if(temp > 20)
    digitalWrite(ledVerde, HIGH);
  else
    digitalWrite(ledVerde, LOW);
  if(temp > 25)
    digitalWrite(ledAmarelo, HIGH);
  else
    digitalWrite(ledAmarelo, LOW);
  if(temp > 28)
    digitalWrite(ledVermelho, HIGH);
  else
    digitalWrite(ledVermelho, LOW);
  delay(2000);
   
}
