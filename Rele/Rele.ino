#include<MeetAndroid.h>

MeetAndroid bluetooth;

int porta_rele1 = 7;
  
void setup()
{
  //Define pinos para o rele como saida
  pinMode(porta_rele1, OUTPUT);
  bluetooth.registerFunction(ControleRele1,'A');
  Serial.begin(9600);
}
   
void loop()
{
  bluetooth.receive();
}

void ControleRele1(byte flag,byte NumOfValues){
  digitalWrite(porta_rele1,bluetooth.getInt());
  Serial.println(bluetooth.getInt());
}

