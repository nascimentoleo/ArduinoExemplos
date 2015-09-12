const byte ledPinEsq[] = {9, 10, 11, 12, 13};
const byte ledPinDir[] = {8, 7, 6, 5, 4};
const byte ledPin[] = {13,12,11,10,9,8,7,6,5,4};
byte bolaNoChao = 1; //Usado para saber se a bola está no chão

int ledDelay(65);
int direcao = 1;
byte currentLED = 0;
const int potenciometro = A0;
unsigned long changeTime;

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledPinEsq[i], OUTPUT);
    pinMode(ledPinDir[i], OUTPUT);
  }
  changeTime = millis();
}

void loop() {
  ledDelay = analogRead(potenciometro);
  if ((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }
}

void changeLED() {
  /*for (int i = 0; i < 5; i++) {
    digitalWrite(ledPinEsq[i], LOW);
  }
  digitalWrite(ledPinEsq[currentLED], HIGH);
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPinDir[i], LOW);
  }
  digitalWrite(ledPinDir[currentLED], HIGH);
  */



  for (int i = 0; i < 10; i ++) {
    digitalWrite(ledPin[i], LOW);
  }

  if (bolaNoChao) {
    digitalWrite(ledPin[9], HIGH);
  }
  else {
    digitalWrite(ledPin[currentLED], HIGH);
    currentLED += direcao;

    if (currentLED == 8) {
      direcao = -1;
    }
    if (currentLED == 0) {
      direcao = 1;
    }

  }

  bolaNoChao = !bolaNoChao;

}

