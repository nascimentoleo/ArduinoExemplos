#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int pinBotaoCelsius = 8;
const int pinBotaoKelvin = 9;
const int pinBotaoFahrenheit = 10; 

const int pinSensorLM35 = A0;
const float constanteProporcionalidade = 0.1075268817;

int flagGrau;

int estadoBotaoCelsius;
int estadoBotaoKelvin;
int estadoBotaoFahrenheit;

float adcLido;

void setup() {
  lcd.begin(16, 2);
  pinMode(pinBotaoCelsius, INPUT);
  pinMode(pinBotaoKelvin, INPUT);
  pinMode(pinBotaoFahrenheit, INPUT);
  analogReference(INTERNAL);
  flagGrau = 1;
}

void loop() {
  estadoBotaoCelsius = digitalRead(pinBotaoCelsius);
  estadoBotaoKelvin = digitalRead(pinBotaoKelvin);  
  estadoBotaoFahrenheit = digitalRead(pinBotaoFahrenheit);

  adcLido = analogRead(pinSensorLM35);
  float temperatura = adcLido * constanteProporcionalidade;

  if(estadoBotaoCelsius || flagGrau == 1){
    displayTemperaturaEmCelsius(temperatura);
    flagGrau = 1;
  }
  if(estadoBotaoKelvin || flagGrau == 2){
    displayTemperaturaEmKelvin(temperatura);
    flagGrau = 2;
  }
  if(estadoBotaoFahrenheit || flagGrau == 3){
    displayTemperaturaEmFahrenheit(temperatura);
    flagGrau = 3;
  }
  
  delay(300);

}

int escreve(String texto, float valor){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(texto);
  lcd.setCursor(0,1);
  lcd.print(valor);
}

void displayTemperaturaEmCelsius(float temperaturaEmGraus){
  escreve("Temperatura em C: ", temperaturaEmGraus);
}

void displayTemperaturaEmKelvin(float temperaturaEmGraus){
  float temperaturaEmKelvin = temperaturaEmGraus + 273.15;
  escreve("Temperatura em K: ", temperaturaEmKelvin);
}

void displayTemperaturaEmFahrenheit(float temperaturaEmGraus){
  float temperaturaEmFahrenheit = (temperaturaEmGraus * 1.8) + 32;
  escreve("Temperatura em F: ", temperaturaEmFahrenheit);
}

