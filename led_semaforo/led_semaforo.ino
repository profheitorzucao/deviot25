int ledVd = 26;
int ledA = 25;
int ledVm = 33;

unsigned long anteriorLed = 0;

const unsigned long intervaloLedVd = 3000;
const unsigned long intervaloLedA = 2000; 
const unsigned long intervaloLedVm = 2000; 

bool estadoLedVd = true;
bool estadoLedA = false;
bool estadoLedVm = false;

void setup() {
  pinMode(ledVd, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledVm, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  
   controlaVerde();
   controlaAmarelo();
   controlaVermelho();
 
}
void controlaVerde() {
  digitalWrite(ledVd, estadoLedVd);
  unsigned long tempoAtual = millis();
  
  if(estadoLedVd){
   if (tempoAtual - anteriorLed >= intervaloLedVd) {
     anteriorLed = tempoAtual;
     Serial.print("oi vd dentro");
     estadoLedVd = false;
     estadoLedA = true;
     estadoLedVm = false; 
   }
  }
}

void controlaAmarelo() {
  digitalWrite(ledA, estadoLedA);
  unsigned long tempoAtual = millis();
  
  if(estadoLedA){
   if (tempoAtual - anteriorLed >= intervaloLedA) {
     anteriorLed = tempoAtual;
     Serial.print("oi A dentro");
     estadoLedVd = false;
     estadoLedA = false;
     estadoLedVm = true; 
   }
  }
}

void controlaVermelho() {
  digitalWrite(ledVm, estadoLedVm);
  unsigned long tempoAtual = millis();
  
  if(estadoLedVm){
   if (tempoAtual - anteriorLed >= intervaloLedVm) {
     anteriorLed = tempoAtual;
     Serial.print("oi vm dentro");
     estadoLedVd = true;
     estadoLedA = false;
     estadoLedVm = false; 
   }
  }
}
