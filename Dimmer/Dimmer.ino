const int PinoPotenciometro = A0;
const int ledVermelho = 9;
const int ledAmarelo = 10;
const int ledVerde = 11;
int ValorPot = 0;
int pwm = 0;
void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  ValorPot = analogRead(PinoPotenciometro);
  if(ValorPot <= 341){
    pwm = map(ValorPot, 0, 341, 0, 255);
    analogWrite(ledVermelho,pwm);
  }
  else if(ValorPot > 341 && ValorPot < 682){
    pwm = map(ValorPot, 341, 682, 0, 255);
    analogWrite(ledAmarelo,pwm);
  }
  else if(ValorPot >= 682){
    pwm = map(ValorPot,682, 1023, 0, 255);
    analogWrite(ledVerde,pwm);
  }

  
}
