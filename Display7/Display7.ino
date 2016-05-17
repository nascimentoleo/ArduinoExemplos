const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;
const int ponto = 9;
int numImpresso;

byte botaoMais = 11;
byte botaoMenos = 12;

void setup() {
  // put your setup code here, to run once:
  for(int i = 2;i <9;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(botaoMais, INPUT);
  pinMode(botaoMenos, INPUT);

  numImpresso = 0;
}


void loop() {
  if(digitalRead(botaoMais))
    numImpresso ++;
  if(digitalRead(botaoMenos))
    numImpresso --;

  if(numImpresso == -1)
    numImpresso = 9;
  else if(numImpresso == 10)
    numImpresso = 0;
     
  switch(numImpresso){
    case 0 : imprimeZERO(); break;
    case 1 : imprimeUM(); break;
    case 2 : imprimeDOIS(); break;
    case 3 : imprimeTRES(); break;
    case 4 : imprimeQUATRO(); break;
    case 5 : imprimeCINCO(); break;
    case 6 : imprimeSEIS(); break;
    case 7 : imprimeSETE(); break;
    case 8 : imprimeOITO(); break;
    case 9 : imprimeNOVE(); break;
  }

  delay(250);
  
}

void imprimeZERO(){
  //Número 0
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,LOW);

}


void imprimeUM(){
  //Número 1
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);

}

void imprimeDOIS(){
  //Número 2
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,LOW);
  digitalWrite(G,HIGH);

}

void imprimeTRES(){
  //Número 3
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,HIGH);

}

void imprimeQUATRO(){
  //Número 4
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);

}

void imprimeCINCO(){
  //Número 5
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,LOW);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);

}

void imprimeSEIS(){
  //Número 6
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);

}

void imprimeSETE(){
  //Número 7
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);

}
void imprimeOITO(){
  //Número 8
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);

}

void imprimeNOVE(){
  //Número 9
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);

}
