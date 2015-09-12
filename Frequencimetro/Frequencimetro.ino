#include <LiquidCrystal.h>

const int btn1 = 8;
const int btn2 = 9;
const int buzzer = 10;
int freq = 0;
int clicouBtn1 = 0;
int clicouBtn2 = 0;
LiquidCrystal lcd(12,11,2,3,4,5);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Frequencia = ");
  lcd.setCursor(6,1);
  lcd.print("Hz");
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
  pinMode(buzzer,OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  clicouBtn1 = digitalRead(btn1);
  clicouBtn2 = digitalRead(btn2);

  if(clicouBtn1){
    freq = freq + 100;
  }
  if(clicouBtn2){
    freq = freq -100;
  }
  if(freq <=0){
    freq = 0;
  }
  if(freq >= 20000){
    freq = 20000;
  }
  if(freq <= 99){
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.setCursor(1,1);
    lcd.print(" ");
    lcd.setCursor(2,1);
    lcd.print(" ");
    lcd.setCursor(3,1);
  }

  if(freq >= 100){
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.setCursor(1,1);
    lcd.print(" ");
    lcd.setCursor(2,1);
  }
  if(freq >= 1000){
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.setCursor(1,1);
  }
  if(freq >= 10000){
    lcd.setCursor(0,1);
  }
  lcd.print(freq);
  tone(buzzer,freq);
  delay(100);
  
}

