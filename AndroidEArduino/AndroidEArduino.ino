#include<MeetAndroid.h>

MeetAndroid bluetooth;

const byte led1 = 2;
const byte led2 = 3;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
  //registrar as funções de retorno
  //que será chamado quando ocorre um evento associado a ela
  bluetooth.registerFunction(ControleLed1,'A');
  bluetooth.registerFunction(ControleLed2,'B');
  
}

void loop() {
  //Recebe os eventos do Amarino
  bluetooth.receive();
}

void ControleLed1(byte flag, byte numOfValues){
  digitalWrite(led1,bluetooth.getInt());
}

void ControleLed2(byte flag, byte numOfValues){
  digitalWrite(led2,bluetooth.getInt());
}

