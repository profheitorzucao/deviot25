int led1 = 25;
int led2 = 26;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}
void loop() {
  piscaLed1();
  piscaLed2(); 
}
void piscaLed1(){
 digitalWrite(led1, HIGH);
 delay(1000);
 digitalWrite(led1, LOW);
 delay(1000);
}

void piscaLed2(){
 digitalWrite(led2, HIGH);
 delay(1500);
 digitalWrite(led2, LOW);
 delay(1500);
}
