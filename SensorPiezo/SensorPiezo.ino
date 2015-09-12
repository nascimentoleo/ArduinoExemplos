const byte ledPin = 3;
const byte piezo = A5;
int threshold = 10; //O valor do sensor a ser atingido antes da ativação
int sensorValue = 0;
float ledValue = 0;

void setup() {
  pinMode(piezo, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); delay(150); digitalWrite(ledPin, LOW); delay(150);
  digitalWrite(ledPin, HIGH); delay(150); digitalWrite(ledPin, LOW); delay(150);
}

void loop() {
  sensorValue = analogRead(piezo);
  if(sensorValue >= threshold){ //Se houver batida
    ledValue = 255;
  }
  analogWrite(ledPin,int(ledValue));
  ledValue = ledValue - 0.05; //Agora apago o led lentamente
  if(ledValue <= 0){
    ledValue = 0;
  }
  
  
  
}
