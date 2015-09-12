#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,2,3,4,5);

const int lm35 = A0;
int ADClido = 0;
float temperatura = 0;
float celsius = 0;
float fahrenheit = 0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  analogReference(INTERNAL);
  configuraLCD();
}

void loop() {
  // put your main code here, to run repeatedly:
  ADClido = analogRead(lm35);
  celsius = ADClido * 0.1075268817204301;
  fahrenheit = (celsius * 1.8) + 32;
  lcd.setCursor(8,0);
  lcd.print(celsius);
  lcd.setCursor(11,1);
  lcd.print(fahrenheit);
  delay(1000);
}

void configuraLCD(){
  lcd.setCursor(0,0);
  lcd.print("Celsius");
  lcd.setCursor(0,1);
  lcd.print("Fahrenheit");
  
}

