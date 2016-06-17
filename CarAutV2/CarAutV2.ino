// inclusão de bibliotecas.
#include <Servo.h>        
#include <Ultrasonic.h>  
#include <AFMotor.h>   //biblioteca de manipulação de motores DCs.  

//definindo os pinos
#define HC_SR04_TRIGGER A1 // Define o pino do Trigger do sensor ultrassônico no pino ANALÓGICO A2  
#define HC_SR04_ECHO A2   // Define o pino do Echo do sensor ultrassônico no pino ANALÓGICO A3  
#define BUZZER A0      
AF_DCMotor motor1(4);    // Define o motor1 ligado ao M3
AF_DCMotor motor2(3);    // Define o motor2 ligado ao M4

Ultrasonic ultrasonic(HC_SR04_TRIGGER,HC_SR04_ECHO);
Servo servo_ultra_sonico; 
int distancia_cm = 0;   //variável do valor da distância

void setup() {
  Serial.begin(9600);

  //configurações do servos motores
  servo_ultra_sonico.attach(10);   // Define o mini servo motor ligado no pino 10.
  pinMode(HC_SR04_TRIGGER, OUTPUT );
  pinMode(HC_SR04_ECHO, INPUT);   
  pinMode(BUZZER, OUTPUT);     
  motor1.setSpeed(170);       // Define a velocidade para os motores 1.A velocidade máxima é 255
  motor2.setSpeed(170);       // Define a velocidade para os motores 2. A velocidade máxima é 255
  servo_ultra_sonico.write(90);   // O servo do sensor se inicia a 90 graus (meio)
  rotacao_Parado;
}

void loop() {
  andar();
}

// Função para chamar outras funções e definir o que o robô fará
void andar() {
  reposicionaServoSonar();
  int distancia = lerSonar(); 
  Serial.print("distancia: "); 
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
   return ultrasonic.Ranging(CM);
}

// Função para calcular a distância do centro
int calcularDistanciaCentro() {
  servo_ultra_sonico.write(75);
  delay(300);
  int leituraDoSonar = lerSonar(); 

  Serial.print("Distancia Centro: ");
  Serial.println(leituraDoSonar);
  return leituraDoSonar;       // Retorna a distância
}

// Função para calcular a distância da direita
int calcularDistanciaDireita() {
  servo_ultra_sonico.write(0);
  delay(300);
  int leituraDoSonar = lerSonar();
  Serial.print("Distancia Direita: ");
  Serial.println(leituraDoSonar);
  return leituraDoSonar;
}

// Função para calcular a distância da esquerda
int calcularDistanciaEsquerda() {
  servo_ultra_sonico.write(180);
  delay(300);
  int leituraDoSonar = lerSonar();
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

// Função para deixar o sensor ultrasonic do robô no centro
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
  digitalWrite(BUZZER, HIGH); 
  delay(500);         
  digitalWrite(BUZZER, LOW);
  delay(50);        
  motor1.run(FORWARD);    // Roda vai para trás
  motor2.run(FORWARD);    // Roda vai para trás
  delay(500);
  tone(A0, 300, 300);
  digitalWrite(BUZZER, HIGH); 
  delay(500);        
  digitalWrite(BUZZER, LOW); 
  delay(50);      

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
