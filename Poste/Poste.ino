const int led = 11;
const int ldr = A0;
int valorLdr = 0;
int pwm = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorLdr = analogRead(ldr);
  Serial.println(valorLdr);
  
  if(valorLdr < 100){
    analogWrite(led,pwm);
    pwm++;
  }else{
    digitalWrite(led,LOW);
    pwm = 0;
  }

  if(pwm > 255){
    pwm = 255;
  }
}
