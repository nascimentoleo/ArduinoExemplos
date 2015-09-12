int valorSensor = 0;
const int buzzer = 11;
const int ldr = A0;
int nota = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorSensor = analogRead(ldr);
  nota = map(valorSensor,300,0,5000,10000);
  tone(buzzer,nota,20);
  delay(10);
}
