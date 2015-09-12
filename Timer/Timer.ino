#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 9, 8, 7, 6, 5);
int segundo = 0;
int minuto = 0;
const int LED13 = 13;
const int buzzer = 11;
const int btn1 = 2;
const int btn2 = 3;
const int btn3 = 4;
int clicouBtn1 = 0;
int clicouBtn2 = 0;
int clicouBtn3 = 0;

void setup() {
  pinMode(LED13, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  lcd.begin(16, 2);
  inicializacao();
}

void loop() {
  //Pego os segundos
  clicouBtn1 = digitalRead(btn1);
  if (clicouBtn1) {
    delay(250); //Uso delay para saber se o botão está pressionado
    if (clicouBtn1) {
      segundo ++;
      if (segundo >= 60) { //Zero ao chegar em 1 minuto
        segundo = 0;
        lcd.setCursor(11, 0);
        lcd.print(" ");
      }
      lcd.setCursor(0, 0);
      lcd.print("Segundos: ");
      lcd.print(segundo);
    }
  }
  //Pego os minutos
  clicouBtn2 = digitalRead(btn2);
  if (clicouBtn2) {
    delay(250); //Uso delay para saber se o botão está pressionado
    if (clicouBtn2) {
      minuto ++;
      if (minuto >= 60) { //Zero ao chegar em 1 hora
        minuto = 0;
        lcd.setCursor(10, 1);
        lcd.print(" ");
      }
      lcd.setCursor(0, 1);
      lcd.print("Minutos: ");
      lcd.print(minuto);
    }
  }

  clicouBtn3 = digitalRead(btn3);
  if (clicouBtn3) {
    if (!((minuto == 0) && (segundo == 0))) {
      iniciarTimer();
    }
  }
}

void iniciarTimer() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("     START     ");
  delay(1000);
  if (segundo == 0) {
    minuto --;
    segundo = 59;
  }
  //Decremento os segundos
  for (int y = 0; y < segundo; y --) {
    if (minuto < 10) {
      lcd.setCursor(5, 1);
      lcd.print("0");
      lcd.print(minuto);
      lcd.print(":");
    } else {
      lcd.setCursor(5, 1);
      lcd.print(minuto);
      lcd.print(":");
    }
    if (segundo < 10) {
      lcd.print("0");
      lcd.print(segundo);
    } else {
      lcd.print(segundo);
    }
    segundo --;
    if (segundo < 0) {
      minuto--;
      segundo = 59;
    }
    delay(1000);
    if ((segundo <= 0) && (minuto <= 0)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.println("Acabou o tempo");
      apitar();
      break; //sai do loop for
    }
  }
  inicializacao();
}
void apitar() {
  digitalWrite(buzzer, HIGH);
  delay(250);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(250);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(250);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);

}

void inicializacao() {
  lcd.begin(16, 2);
  lcd.print("Selecione o ");
  lcd.setCursor(0, 1);
  lcd.print("tempo do timer..");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Segundos: ");
  lcd.print(segundo);
  lcd.setCursor(0, 1);
  lcd.print("Minutos: ");
  lcd.print(minuto);
}


