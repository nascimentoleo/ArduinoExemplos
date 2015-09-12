const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;
const int buzzer = 12;
void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL); //Se estiver usando Arduino Mega, use INTERNAL1V1
  pinMode(buzzer,OUTPUT);
}
void loop() {
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817204301;
  if(temperatura > 32){
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }

  Serial.print("Temperatura = ");
  Serial.print(temperatura);
  Serial.println(" C");

}
