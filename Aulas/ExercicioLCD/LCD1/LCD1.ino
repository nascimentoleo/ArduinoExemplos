#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
    
}

void loop() {
  lcd.clear();
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Crime ocorre,");
  delay(3000);
  lcd.setCursor(0,1);
  lcd.print("Nada acontece");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FEIJOADA !!");
  delay(3000);;
}


