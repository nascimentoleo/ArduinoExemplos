#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,2,3,4,5);

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Ola");
}

void loop() {
  // put your main code here, to run repeatedly:


}
