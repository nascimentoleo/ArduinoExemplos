#include <Servo.h>

char buffer[10];
Servo servo1;
Servo servo2;

void setup() {
  servo1.attach(5);
  servo2.attach(6);
  Serial.begin(9600);
  Serial.flush();
  servo1.write(90);
  servo2.write(90);
  Serial.println("STARTING...");
}

void loop() {
  if (Serial.available() > 0){
    int index = 0;
    delay(100);
    int numChar = Serial.available();
    if(numChar > 10){
      numChar = 10;
    }

    while (numChar --){
      buffer[index++] = Serial.read();
    }
    splitString(buffer);
  }
}

void splitString(char* data){
  Serial.print("Data entered: ");
  Serial.println(data);
  char* parameter;
  parameter = strtok(data, " , ");
  while(parameter != NULL){
    setServo(parameter);
    parameter = strtok(NULL," , ");
  }
  for (int x=0;x<9;x++){
    buffer[x] = '\0';
  }
  Serial.flush();
}

void setServo(char* data){
  if((data[0] == 'L') || (data[0] == 'l')){
    int firstVal = strtol(data + 1, NULL,10);
    firstVal = constrain(firstVal,0,180);
    servo1.write(firstVal);
    Serial.print("Servo1 is set to: ");
    Serial.println(firstVal);
  }
  
  if((data[0] == 'R') || (data[0] == 'r')){
    int secondVal = strtol(data + 1, NULL,10);
    secondVal = constrain(secondVal,0,255);
    servo2.write(secondVal);
    Serial.print("Servo2 is set to: ");
    Serial.println(secondVal);
  }
}

