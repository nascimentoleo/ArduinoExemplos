const int LDR = A0;
const int LM35 = A1;
const int Buzzer = 9;
const int led[] = {
  2, 3, 4, 5, 6, 7, 8
};
int ValorLDR = 0;
int ADClido = 0;
float temperatura = 0;
int pwm = 0;
void setup() {
  for (int x = 0; x < 7 ; x++) {
    pinMode(led[x], OUTPUT);
  }
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  ValorLDR = analogRead(LDR);
  Serial.println(ValorLDR);
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.48828125;
  if (temperatura > 28.00) {
    digitalWrite(led[0], HIGH);
  }
  else {
    digitalWrite(led[0], LOW);
  }
  if (temperatura > 29.00) {
    digitalWrite(led[1], HIGH);
  }
  else {
    digitalWrite(led[1], LOW);
  }
  if (temperatura > 30.00) {
    digitalWrite(led[2], HIGH);
  }
  else {
    digitalWrite(led[2], LOW);
  }
  if (ValorLDR > 100) {
    digitalWrite(led[5], HIGH);
  }
  else {
    digitalWrite(led[5], LOW);
  }
  if (ValorLDR > 200) {
    digitalWrite(led[4], HIGH);
  }
  else {
    digitalWrite(led[4], LOW);
  }
  if (ValorLDR > 300) {
    digitalWrite(led[3], HIGH);
    digitalWrite(led[6], LOW);
 
  }
  else {
    digitalWrite(led[3], LOW);
    digitalWrite(led[6], HIGH);
  }
}
