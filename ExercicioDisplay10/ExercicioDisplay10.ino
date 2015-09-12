
const int display[] = {2,3,4,5,6,7,8,9,10,11};
void setup() {
  // put your setup code here, to run once:
  for(int i =0;i<10;i++){
    pinMode(display[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0;i < 10; i++){
      digitalWrite(display[i],HIGH);
      delay(300);  
  }
  for(int i = 9;i >= 0; i--){
      digitalWrite(display[i],LOW);  
      delay(300);
  }
  
}
