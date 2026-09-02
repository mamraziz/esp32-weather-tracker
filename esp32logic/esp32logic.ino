#include <WiFi.h>
#include <HTTPClient.h>
#include "secrets.h"

//const char* ssid = "";
//const char* password = "";
//remove screts.h and uncomment ssid and password

int ldrS = 3;
int tempS = 5;
int humS = 6;
int ldr;
int temp;
int hum;

HTTPClient http;

void setup() {
  // put your setup code here, to run once:
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  pinMode(ldrS, INPUT);
  pinMode(tempS, INPUT);
  pinMode(humS, INPUT);
  Serial.begin(9600); // delete this
}

void loop() {
  // put your main code here, to run repeatedly:
  ldr = analogRead(ldrS);
  temp = analogRead(tempS); 
  hum = analogRead(humS);
  Serial.println(ldr + temp + hum); // delete this

  http.begin("http://192.168.1.11:3000/readings");
  http.addHeader("Content-Type", "application/json");
  String body = "{\"ldr\": " + String(ldr) + ", \"temp\": " + String(temp) + ", \"hum\": " + String(hum) + "}";
  int responseCode = http.POST(body);
  http.end();
  delay(30000);
}
