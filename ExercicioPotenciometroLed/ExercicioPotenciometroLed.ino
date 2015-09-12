const int barraLed[10] = {2,3,4,5,6,7,8,9,10,12};
const int led = 11;
const int potenciometro = A0;
int valorPotenciometro = 0;
int valorLed = 0;

void setup() {
  for(int i = 0; i <10; i++){
    pinMode(barraLed[i],OUTPUT);
  }
  pinMode(led,OUTPUT);

}

void loop() {
  valorPotenciometro = analogRead(potenciometro);
  valorLed = map(valorPotenciometro,0,1023,0,255);
  analogWrite(led,valorLed);
  //Agora irei acender os leds da barra de acordo com a intensidade da luz
  if(valorLed > 25){
    digitalWrite(barraLed[0],HIGH);
  }else{
    digitalWrite(barraLed[0],LOW);
  }
  if(valorLed > 50){
    digitalWrite(barraLed[1],HIGH);
  }else{
    digitalWrite(barraLed[1],LOW);
  }
  if(valorLed > 75){
    digitalWrite(barraLed[2],HIGH);
  }else{
    digitalWrite(barraLed[2],LOW);
  }
  
  if(valorLed > 100){
    digitalWrite(barraLed[3],HIGH);
  }else{
    digitalWrite(barraLed[3],LOW);
  }
  
  if(valorLed > 125){
    digitalWrite(barraLed[4],HIGH);
  }else{
    digitalWrite(barraLed[4],LOW);
  }
  
  if(valorLed > 150){
    digitalWrite(barraLed[5],HIGH);
  }else{
    digitalWrite(barraLed[5],LOW);
  }
  
  if(valorLed > 175){
    digitalWrite(barraLed[6],HIGH);
  }else{
    digitalWrite(barraLed[6],LOW);
  }
  
  if(valorLed > 200){
    digitalWrite(barraLed[7],HIGH);
  }else{
    digitalWrite(barraLed[7],LOW);
  }
  
  if(valorLed > 225){
    digitalWrite(barraLed[8],HIGH);
  }else{
    digitalWrite(barraLed[8],LOW);
  }
  
  if(valorLed > 250){
    digitalWrite(barraLed[9],HIGH);
  }else{
    digitalWrite(barraLed[9],LOW);
  }
}
