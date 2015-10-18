// inclusão de bibliotecas.
#include <Servo.h>    // inclui biblioteca de manipulação de servos motores.    
#include <Ultrasonic.h> // inclui biblioteca de manipulação do sensor ultrassônico.    
#include <AFMotor.h>   // inclui biblioteca de manipulação de motores DCs.  

//definindo os pinos
#define HC_SR04_TRIGGER A1 // Define o pino do Trigger do sensor ultrassônico no pino ANALÓGICO A2  
#define HC_SR04_ECHO A2   // Define o pino do Echo do sensor ultrassônico no pino ANALÓGICO A3  
#define BUZZER A0      // Define o pino do buzzer (Som) no pino ANALÓGICO A0  
AF_DCMotor motor1(4);    // Define o motor1 ligado ao M3
AF_DCMotor motor2(3);    // Define o motor2 ligado ao M4

Ultrasonic ultrasonic(HC_SR04_TRIGGER,HC_SR04_ECHO);
Servo servo_ultra_sonico; // nomeando o servo motor
int distancia_cm = 0;   //variável do valor da distância

// executado na inicialização do Arduino
void setup() {
  Serial.begin(9600); // inicializa a comunicação serial para mostrar dados

  //configurações do servos motores
  servo_ultra_sonico.attach(10);   // Define o mini servo motor ligado no pino 10.
  pinMode(HC_SR04_TRIGGER, OUTPUT ); // Define o trigger do sensor para enviar o sinal
  pinMode(HC_SR04_ECHO, INPUT);   // Define o Echo do sensor para receber o sinal
  pinMode(BUZZER, OUTPUT);     // Define o pino do buzzer como saída
  motor1.setSpeed(130);       // Define a velocidade para os motores 1.A velocidade máxima é 255
  motor2.setSpeed(130);       // Define a velocidade para os motores 2. A velocidade máxima é 255
  servo_ultra_sonico.write(90);   // O servo do sensor se inicia a 90 graus (meio)
  rotacao_Parado;
}

// Função principal do Arduino
void loop() {
  andar();
}

// Função para chamar outras funções e definir o que o robô fará
void andar() {
  reposicionaServoSonar();
  int distancia = lerSonar(); // Ler o sensor de distância
  Serial.print("distancia: "); // Exibe no serial
  Serial.println(distancia);
  if (distancia > 25) {
    rotacao_Frente();
  } else {
    rotacao_Parado();
    posicionaCarroMelhorCaminho();
    andar();
  }
}

// Função para ler e calcular a distância do sensor ultrassônico
int lerSonar() {
  /*digitalWrite(HC_SR04_TRIGGER, LOW);     // Desliga a emisão do som
  delayMicroseconds(4);            // Aguarda 4 segundos
  digitalWrite(HC_SR04_TRIGGER, HIGH);     // Liga a trasmisão de som
  delayMicroseconds(20);            // Continua emitindo o som durante 20 segundos
  digitalWrite(HC_SR04_TRIGGER, LOW);     // Desliga a emisão do som
  delayMicroseconds(10);            // Aguarda 10 segundos para poder receber o som
  long pulse_us = pulseIn(HC_SR04_ECHO, HIGH); // Liga o recebedor e calcula quandos pulsos ele recebeu
  distancia_cm = pulse_us / 59;        // Calcula a distaâcia em CM
  delay(300);
  return distancia_cm;             // Retorna a distância*/
  return ultrasonic.Ranging(CM);
}

// Função para calcular a distância do centro
int calcularDistanciaCentro() {
  servo_ultra_sonico.write(75);
  delay(300);
  int leituraDoSonar = lerSonar();  // Ler sensor de distância
  /*delay(600);
  leituraDoSonar = lerSonar();
  delay(600); */
  Serial.print("Distancia Centro: "); // Exibe no serial
  Serial.println(leituraDoSonar);
  return leituraDoSonar;       // Retorna a distância
}

// Função para calcular a distância da direita
int calcularDistanciaDireita() {
  servo_ultra_sonico.write(0);
  delay(300);
  int leituraDoSonar = lerSonar();
  /*delay(600);
  leituraDoSonar = lerSonar();
  delay(600); */
  Serial.print("Distancia Direita: ");
  Serial.println(leituraDoSonar);
  return leituraDoSonar;
}

// Função para calcular a distância da esquerda
int calcularDistanciaEsquerda() {
  servo_ultra_sonico.write(180);
  delay(300);
  int leituraDoSonar = lerSonar();
  /*delay(600);
  leituraDoSonar = lerSonar();
  delay(600); */
  Serial.print("Distancia Esquerda: ");
  Serial.println(leituraDoSonar);
  return leituraDoSonar;
}

// Função para pegar as distâncias lidas e calcular qual a melhor distancia
char calculaMelhorDistancia() {
  int esquerda = calcularDistanciaEsquerda();
  int centro = calcularDistanciaCentro();
  int direita = calcularDistanciaDireita();
  reposicionaServoSonar();
  int maiorDistancia = 0;
  char melhorDistancia = '0';

  if (centro > direita && centro > esquerda) {
    melhorDistancia = 'c';
    maiorDistancia = centro;
  } else if (direita > centro && direita > esquerda) {
    melhorDistancia = 'd';
    maiorDistancia = direita;
  } else if (esquerda > centro && esquerda > direita) {
    melhorDistancia = 'e';
    maiorDistancia = esquerda;
  }
  if (maiorDistancia <= 25) {
    rotacao_Re();
    posicionaCarroMelhorCaminho();
  }
  reposicionaServoSonar();
  return melhorDistancia;
}

// Função para colocar o carrinho na melhor distância, isto é, girá-lo para a melhor distância
void posicionaCarroMelhorCaminho() {
  char melhorDist = calculaMelhorDistancia();
  Serial.print("melhor Distancia: ");
  Serial.println(melhorDist);
  if (melhorDist == 'c') {
    andar();
  } else if (melhorDist == 'd') {
    rotacao_Direita();
  } else if (melhorDist == 'e') {
    rotacao_Esquerda();
  } else {
    rotacao_Re();
  }
  reposicionaServoSonar();
}

// Função para deixar o sensor "olho" do robô no centro
void reposicionaServoSonar() {
  servo_ultra_sonico.write(75);
  delay(200);
}

// Função para fazer o carro parar
void rotacao_Parado()
{
  Serial.println(" Parar ");
  motor1.run(RELEASE); // Motor para
  motor2.run(RELEASE);
}

// Função para fazer o robô andar para frente
void rotacao_Frente()
{
  Serial.println(" frente ");
  motor1.run(BACKWARD); // Roda vai para frente
  motor2.run(BACKWARD); // Roda vai para frente
  delay(500);
}

// Função que faz o robô andar para trás e emite som quando ele dá ré
void rotacao_Re()
{
  Serial.println(" ré ");
  tone(A0, 300, 300);    // Configuração do tom do som
  digitalWrite(BUZZER, HIGH); // Liga o som
  delay(500);         // Aguarda durante 250 milesecundos
  digitalWrite(BUZZER, LOW); // Desliga o som
  delay(50);         // Aguarda durante 250 milesecundos
  motor1.run(FORWARD);    // Roda vai para trás
  motor2.run(FORWARD);    // Roda vai para trás
  delay(500);
  tone(A0, 300, 300);
  digitalWrite(BUZZER, HIGH); // Liga o som
  delay(500);         // Aguarda durante 250 milesecundos
  digitalWrite(BUZZER, LOW); // Desliga o som
  delay(50);         // Aguarda durante 250 milesecundos

  rotacao_Parado();
}

// Função que faz o robô virar à direita
void rotacao_Direita()
{
  Serial.println(" Para a direita ");
  motor1.run(FORWARD); // Roda vai para frente
  motor2.run(BACKWARD); // Roda vai para trás
  delay(100);
}

// Função que faz o robô virar à esquerda
void rotacao_Esquerda()
{
  Serial.println(" Para a esquerda ");
  motor1.run(BACKWARD); // Roda vai para trás
  motor2.run(FORWARD); // Roda vai para frente
  delay(100);
}
