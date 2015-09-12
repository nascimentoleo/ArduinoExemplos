const int carGreen = 10;
const int carYellow = 9;
const int carRed = 8;
const int btn = 12;
const int pedRed = 3;
const int pedGreen = 2;
int crossTime = 5000;
unsigned long changeTime;

void setup() {
  pinMode(carGreen,OUTPUT);
  pinMode(carYellow,OUTPUT);
  pinMode(carRed,OUTPUT);
  pinMode(pedRed,OUTPUT);
  pinMode(pedGreen,OUTPUT);
  pinMode(btn,INPUT);

  digitalWrite(carGreen,HIGH);
  digitalWrite(pedRed,HIGH);
  
}

void loop() {
  //Verifico se foi pressiona e se faz mais de 5s que o sinal está aberto
  if(digitalRead(btn) && (millis() - changeTime > 5000) ){
    changeLights();
    
  }
}

void changeLights(){
  digitalWrite(carGreen,LOW);
  digitalWrite(carYellow,HIGH);
  delay(2000);

  digitalWrite(carYellow,LOW);
  digitalWrite(carRed,HIGH);
  delay(1000);
  
  digitalWrite(pedRed,LOW);
  digitalWrite(pedGreen,HIGH);
  delay(crossTime);
  
  //Pisca para avisar que o sinal de pedestres irá fechar
  for(int i = 0; i < 10; i ++){
    digitalWrite(pedGreen,HIGH);
    delay(250);
    digitalWrite(pedGreen,LOW);
    delay(250);
  }

  digitalWrite(pedRed,HIGH);
  delay(500);
  digitalWrite(carRed,LOW);
  digitalWrite(carGreen,HIGH);

  changeTime = millis();
  
}

