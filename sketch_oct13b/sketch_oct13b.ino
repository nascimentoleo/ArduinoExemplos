// inclusão de bibliotecas.    
  #include <Servo.h>    // inclui biblioteca de manipulação de servos motores.    
  #include <Ultrasonic.h> // inclui biblioteca de manipulação do sensor ultrassônico.    
  #include <AFMotor.h>   // inclui biblioteca de manipulação de motores DCs.  
    
  //definindo os pinos  
  #define HC_SR04_TRIGGER A2 // Define o pino do Trigger do sensor ultrassônico no pino ANALÓGICO A2  
  #define HC_SR04_ECHO A3   // Define o pino do Echo do sensor ultrassônico no pino ANALÓGICO A3  
  #define BUZZER A0      // Define o pino do buzzer (Som) no pino ANALÓGICO A0  
  AF_DCMotor motor1(1);    // Define o motor1 ligado ao M3  
  AF_DCMotor motor2(3);    // Define o motor2 ligado ao M4  
    
  Servo servo_ultra_sonico; // nomeando o servo motor    
  int distancia_cm = 0;   //variável do valor da distância  
    
  // executado na inicialização do Arduino    
  void setup(){    
   Serial.begin(9600); // inicializa a comunicação serial para mostrar dados   
     
   motor1.setSpeed(190);       // Define a velocidade para os motores 1.A velocidade máxima é 255  
   motor2.setSpeed(190);       // Define a velocidade para os motores 2. A velocidade máxima é 255  
   }    
    
  // Função principal do Arduino    
  void loop(){    
    motor1.run(FORWARD); // Roda vai para frente  
    motor2.run(FORWARD); // Roda vai para frente  
  }    
  
