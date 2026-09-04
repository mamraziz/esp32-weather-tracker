#include <WiFi.h>
#include <HTTPClient.h>
#include "secrets.h"
#include "DHT.h"
#define DHTPIN 26
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int ldrS = 25;
float ldr;
float temp;
float hum;

HTTPClient http;

void setup() {
  // put your setup code here, to run once:
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  pinMode(ldrS, INPUT);
  Serial.begin(9600); // delete this
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  ldr = analogRead(ldrS);
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  Serial.println(temp); // delete this
  Serial.println(hum);

  http.begin("http://192.168.1.11:3000/readings");
  http.addHeader("Content-Type", "application/json");
  String body = "{\"ldr\": " + String(ldr) + ", \"temp\": " + String(temp) + ", \"hum\": " + String(hum) + "}";
  int responseCode = http.POST(body);
  http.end();
  delay(30000);
}
