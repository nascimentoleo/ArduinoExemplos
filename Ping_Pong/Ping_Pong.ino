#include<LiquidCrystal.h>

LiquidCrystal lcd(11, 10, 2, 3, 4, 5);
const int btnPlayer1 = 12;
const int btnPlayer2 = 13;
int posicaoBola = 1;
int bolaVoltando = 0;
int pontuacao1 = 0, pontuacao2 = 0;
int valorDelay = 200;


void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(btnPlayer1, INPUT);
  pinMode(btnPlayer2, INPUT);

  iniciarJogo();
}

void loop() {
  if (pontuacao1 == 13 || pontuacao2 == 13) {
    gameOver();
  }

  //Valido se a bola está indo ou voltando no lcd
  if (posicaoBola == 1) {
    bolaVoltando = 0;
    if (valorDelay > 30) {
      valorDelay = valorDelay - 30; //Faço isso para cada rodada ser mais rápida
    }
  }
  if (posicaoBola == 14) {
    bolaVoltando = 1;
  }
  lcd.setCursor(posicaoBola, 0);
  lcd.print("o");
  
  delay(valorDelay);
  //Aqui verificarei se a bola está na frente de uma das raquetes.
  //Caso esteja, se o botão referente ao jogador estiver pressionado, esse jogador ganha ponto
  if (posicaoBola == 1) {
    if (digitalRead(btnPlayer1)) {
      pontuar(1);
    }
  }
  if (posicaoBola == 14) {
    if (digitalRead(btnPlayer2)) {
      pontuar(2);
    }
  }

  //Limpo a posição onde imprimir a bola, para que ela "suma"
  lcd.setCursor(posicaoBola, 0);
  lcd.print(" ");

  //Aqui controlo os contadores para fazer a bola andar
  //Se incrementar a bola irá para frente, e vice versa
  if (bolaVoltando) {
    posicaoBola --;
  } else {
    posicaoBola ++;
  }
}

void pontuar(int player) {
  if (player == 1) {
    pontuacao1 ++;
    lcd.setCursor(0, 1);
    lcd.print(pontuacao1);
  } else {
    pontuacao2 ++;
    //Se for maior que nove, terei que posicionar o cursor 1 casa antes, pq serão 2 dígitos
    if (pontuacao2 > 9) {
      lcd.setCursor(14, 1);
    } else {
      lcd.setCursor(15, 1);
    }
    lcd.print(pontuacao2);

  }
}

void iniciarJogo() {
  //Configuro as raquetes
  lcd.setCursor(0, 0);
  lcd.print("|");
  lcd.setCursor(15, 0);
  lcd.print("|");

  //Pontuação inicial
  lcd.setCursor(0, 1);
  lcd.print("0");
  lcd.setCursor(15, 1);
  lcd.print("0");

  posicaoBola = 1;
}

void gameOver() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("GAME OVER");
  lcd.setCursor(0, 1);
  //Verifico o vencedor
  if (pontuacao1 > pontuacao2) {
    lcd.print("PLAYER 1 VENCEU");
  } else {
    lcd.print("PLAYER 2 VENCEU");
  }
  valorDelay = 200;
  pontuacao1 = 0;
  pontuacao2 = 0;

  delay(5000);
  lcd.clear();
  iniciarJogo();

}

