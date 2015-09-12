#define abre 60
#define fecha 180
#define centro 90
#define esquerda 150
#define direita 30

#define olhos 8

#include <Servo.h>

Servo servoboca, servocabeca;

char buffer[10];

boolean olhosAcesos = false;
boolean statuscentrocabeca = false;
boolean cabecaesq = true;
boolean cabecadir = false;
boolean bocafechada = true;

void setup() {
  pinMode(olhos, OUTPUT);
  servoboca.attach(9);
  servocabeca.attach(10);
  servoboca.write(fecha);
  servocabeca.write(135);
  digitalWrite(olhos, LOW);
  Serial.begin(9600);
}


void loop() {
  if (Serial.available() > 0) {
    int index = 0;
    delay(100);
    int numChar = Serial.available();
    if (numChar > 10) {
      numChar = 10;
    }
    while (numChar --) {
      buffer[index++] = Serial.read();
    }

    mandarComando(buffer, index);
  }

}

void mandarComando(char* comando, int qtd) {
  for (int i = 0; i < qtd; i ++) {
    switch (comando[i]) {
      case 'o' : acenderOlhos();
        break;
      case 'e' : virarEsquerda();
        break;
      case 'd' : virarDireita();
        break;
      case 'a' : abrirBoca();
        break;
      case 'f' : fecharBoca();
        break;
    }
    delay(300);
  }
}

void acenderOlhos() {
  olhosAcesos = !olhosAcesos;
  digitalWrite(olhos, olhosAcesos);
}

void virarEsquerda() {
  if (cabecadir) {
    servocabeca.write(esquerda);
    cabecaesq = true;
    cabecadir = false;
  } else {
    piscarOlhos();
  }
}

void virarDireita() {
  if (cabecaesq) {
    servocabeca.write(direita);
    cabecaesq = false;
    cabecadir = true;
  } else {
    piscarOlhos();
  }
}

void fecharBoca() {
  if (!bocafechada) {
    servoboca.write(fecha);
    bocafechada = true;
  } else {
    piscarOlhos();
  }
}

void abrirBoca(){
  if (bocafechada) {
    servoboca.write(abre);
    bocafechada = false;
  } else {
    piscarOlhos();
  }
}

//Pisca os olhos toda vez que um comando é impossível
void piscarOlhos() {
  digitalWrite(olhos, LOW);
  delay(150);
  digitalWrite(olhos, HIGH);
  delay(150);
  digitalWrite(olhos, LOW);
  delay(150);
  digitalWrite(olhos, HIGH);
}

