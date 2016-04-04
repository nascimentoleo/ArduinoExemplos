byte led = 9;
int ldr = A1;
int valorLDR;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);  
}

void loop() {
  valorLDR = analogRead(ldr);
  Serial.println(valorLDR);
  if(valorLDR > 300)
    digitalWrite(led,LOW);
  else
    digitalWrite(led,HIGH);  
  delay(500);
}
 
