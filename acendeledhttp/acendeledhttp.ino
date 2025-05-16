#include <WiFi.h>
#include <WebServer.h>
#include <string.h>

WebServer server(80);

const char *ssid = "Wifi-Heitor";
const char *password= "12345678";

IPAddress local_IP(192,168,0,80);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

int tempAcende1=10000;
int tempAcende2=10000;
int tempAcende3=10000;

unsigned long tempo =10000;

enum State{  // Estados da máquina de estados
  ACENDER_1,
  ACENDER_2,
  ACENDER_3,
  COMPLETO
};

State currentState = ACENDER_1;


const int pinLed1 = 2;
const int pinLed2 = 4;
const int pinLed3 = 19;

void setup() {
  Serial.begin(115200);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  //Configuração do Acess Point que ira ser fornecido pelo ESP32
  Serial.print("Configurando AP.....");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet)? "OK" : "Erro");
  Serial.print("Iniciando o Wifi.....");
  Serial.println(WiFi.softAP(ssid, password));
  Serial.print("Endereço IP");
  Serial.println(WiFi.softAPIP());
  
  server.on("/", handleIndex);
  server.on("/acende", handleAcende);
  server.begin();
 
}

void loop() {
  server.handleClient();
  acendeMaster();
}

void handleIndex(){
  String texto ="oi";
  String html;
  html = "<!DOCTYPE html>";
  html += "<html lang='pt-br'>";
  html += "<head>";
  html += "<meta charset='UTF-8'>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<title>Acende Led</title>";
  html += "</head>";
  html += "<body>";
  html += "<form action='/acende'>";
  html += "<label for='temp1'>Tempo1:</label>";
  html += "<br>";
  html += "<input type='text' name='txtTime1' id=''>";
  html += "<br>";
  html += "<label for='temp2'>Tempo1:</label>";
  html += "<br>";
  html += "<input type='text' name='txtTime2' id=''>";
  html += "<br>";
  html += "<label for='temp3'>Tempo1:</label>";
  html += "<br>";
  html += "<input type='text' name='txtTime3' id=''>";
  html += "<br>";
  html += "<input type='submit' value='Enviar'>";
  html += "</form>";
  html += "</body>";
  html += "</html>";
  server.send(200, "text/html", html);
}

void handleAcende(){
  tempAcende1 = atoi(server.arg("txtTime1").c_str())*1000;
  tempAcende2 = atoi(server.arg("txtTime2").c_str())*1000;
  tempAcende3 = atoi(server.arg("txtTime2").c_str())*1000;
  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "");
}

void acendeMaster(){
  unsigned long currentMillis = millis();  // Obtém o tempo atual

  switch (currentState) {
    case ACENDER_1:
       acenderLed(pinLed1);
      if (currentMillis - tempo >= tempAcende1) {
        tempo = currentMillis;
        apagaLed(pinLed1);
        currentState = ACENDER_2;
      }
      break;
    case ACENDER_2:
      acenderLed(pinLed2);
      if (currentMillis - tempo >= tempAcende2) {
        tempo = currentMillis;
        apagaLed(pinLed2);
        currentState = ACENDER_3;
      }
      break;
    case ACENDER_3:
      acenderLed(pinLed3);
      if (currentMillis - tempo >= tempAcende3) {
        tempo = currentMillis;
        apagaLed(pinLed3);
        currentState = COMPLETO;
      }
      break;
    case COMPLETO:
        currentState = ACENDER_1;
        break;
  }
}

void acenderLed(int pino){
  digitalWrite(pino, HIGH);
}

void apagaLed(int pino){
  digitalWrite(pino, LOW);
}
