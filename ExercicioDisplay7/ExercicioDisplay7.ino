const int a = 7;
const int b = 6;
const int c = 5;
const int d = 4;
const int btn = 2;
const int matrizNumeros [6][4] = { //Número de 1 a 6 em binário
  {0, 0, 0, 1},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 1, 0, 0},
  {0, 1, 0, 1},
  {0, 1, 1, 0}
};

int numeroRand;
void setup() {
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {
  if (digitalRead(btn)) {
    delay(100);
    if (digitalRead(btn)) {
      numeroRand = random(6);
      digitalWrite(a, matrizNumeros[numeroRand][0]);
      digitalWrite(b, matrizNumeros[numeroRand][1]);
      digitalWrite(c, matrizNumeros[numeroRand][2]);
      digitalWrite(d, matrizNumeros[numeroRand][3]);
    }
  }
}

