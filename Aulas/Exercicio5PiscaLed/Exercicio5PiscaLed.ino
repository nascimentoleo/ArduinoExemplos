byte led = 8;
int potenciometro = A0;
int valorPotenciometro;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(potenciometro, INPUT);
  Serial.begin(9600);  
}

void loop() {
  digitalWrite(led,HIGH);
  valorPotenciometro = analogRead(potenciometro);
  Serial.println(valorPotenciometro);
  delay(valorPotenciometro);
  digitalWrite(led,LOW);
  delay(valorPotenciometro);
}
