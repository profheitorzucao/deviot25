int led1 = 25;
int led2 = 26;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  dacWrite(led1, 255);
  dacWrite(led2, 0);
  delay(500);
  dacWrite(led1, 128);
  dacWrite(led2, 128);
  delay(500);
  dacWrite(led1, 0);
  dacWrite(led2, 255);
  delay(500);
}
