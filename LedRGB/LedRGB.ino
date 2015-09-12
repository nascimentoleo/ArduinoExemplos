const int R = 9;
const int G = 10;
const int B = 11;
int valorRed = 255;
int valorGreen = 0;
int valorBlue = 0;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  analogWrite(R, valorRed);
  analogWrite(G, valorGreen);
  analogWrite(B, valorBlue);
}

void loop() {
  for (valorGreen = 0; valorGreen < 255; valorGreen = valorGreen + 5) {
    analogWrite(G, valorGreen);
    delay(50);
  }
  for (valorRed = 255; valorRed > 0; valorRed = valorRed - 5) {
    analogWrite(R, valorRed);
    delay(50);
  }
  for (valorBlue = 0; valorBlue < 255; valorBlue = valorBlue + 5) {
    analogWrite(B, valorBlue);
    delay(50);
  }
  for (valorGreen = 255; valorGreen > 0; valorGreen = valorGreen - 5) {
    analogWrite(G, valorGreen);
    delay(50);
  }
  for (valorRed = 0; valorRed < 255; valorRed = valorRed + 5) {
    analogWrite(R, valorRed);
    delay(50);
  }
  for (valorBlue = 255; valorBlue > 0; valorBlue = valorBlue - 5) {
    analogWrite(B, valorBlue);
    delay(50);
  }

}
