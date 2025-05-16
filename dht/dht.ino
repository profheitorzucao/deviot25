#include "DHT.h"
#define DHTTYPE DHT11
const int pindht = 4;
DHT dht(pindht, DHTTYPE);
float temp;
float umi;
void setup() {
pinMode(pindht, INPUT);
dht.begin();
Serial.begin(115200);
}
void loop() {
  temp =  dht.readTemperature();
  umi = dht.readHumidity();
  Serial.print("Temperatura:");
  Serial.println(temp);
  Serial.print("Umidade:");
  Serial.println(umi);

  delay(1000);
}
