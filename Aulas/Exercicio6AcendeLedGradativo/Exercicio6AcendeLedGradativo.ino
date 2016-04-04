byte led = 9;
int potenciometro = A0;
int valorPotenciometro;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(potenciometro, INPUT);
  Serial.begin(9600);  
}

void loop() {
  valorPotenciometro = analogRead(potenciometro);
  valorPotenciometro = map(valorPotenciometro, 0, 1023, 0, 255);
  Serial.println(valorPotenciometro);
  analogWrite(led, valorPotenciometro);
  delay(50);
}
 
