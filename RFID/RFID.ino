#include <MFRC522.h>
#include <SPI.h>
#include<LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal lcd(6, 7, 5, 4, 3, 2);

char st[20];

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Aproxime o seu cartao do leitor ...");
  Serial.println();
  lcd.begin(16, 2);
  mensagemInicial();
}

void loop() {
  if (! mfrc522.PICC_IsNewCardPresent())
    return;
  if (! mfrc522.PICC_ReadCardSerial())
    return;

  Serial.print("UID da tag :");
  String conteudo = "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i ++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();

  //uid do chaveiro
  if (conteudo.substring(1) == "F9 AF 5E 9E") {
    Serial.println("Olá Leo");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ola Leo");
    lcd.setCursor(0, 1);
    lcd.print("Acesso liberado!");
    delay(3000);
    mensagemInicial();
  }

  //UID DO CARTAO
  if (conteudo.substring(1) == "C4 37 A5 85") {
    Serial.println("Olá Cartao");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ola Cartao");
    lcd.setCursor(0, 1);
    lcd.print("Acesso Negado!");
    delay(3000);
    mensagemInicial();
  }

  //UID DO CARTAO
  if (conteudo.substring(1) == "E7 DB 4D E5") {
    Serial.println("Olá Estudante");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ola Estudante");
    lcd.setCursor(0, 1);
    lcd.print("Valor descontadox'!");
    delay(3000);
    mensagemInicial();
  }
}

void mensagemInicial() {
  lcd.clear();
  lcd.print(" Aproxime o seu");
  lcd.setCursor(0,1);
  lcd.print("cartao do leitor");
}

