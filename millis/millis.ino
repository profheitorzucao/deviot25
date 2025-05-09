int led1 = 25;
int led2 = 26;

unsigned long anteriorLed1 = 0;
unsigned long anteriorLed2 = 0;

const unsigned long intervaloLed1 = 1000; // 1 segundo
const unsigned long intervaloLed2 = 1500; // 1,5 segundos

bool estadoLed1 = false;
bool estadoLed2 = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  piscaLed1();
  piscaLed2();
}

void piscaLed1() {
  unsigned long tempoAtual = millis();
  if (tempoAtual - anteriorLed1 >= intervaloLed1) {
    anteriorLed1 = tempoAtual;
    estadoLed1 = !estadoLed1;
    digitalWrite(led1, estadoLed1);
  }
}

void piscaLed2() {
  unsigned long tempoAtual = millis();
  if (tempoAtual - anteriorLed2 >= intervaloLed2) {
    anteriorLed2 = tempoAtual;
    estadoLed2 = !estadoLed2;
    digitalWrite(led2, estadoLed2);
  }
}
