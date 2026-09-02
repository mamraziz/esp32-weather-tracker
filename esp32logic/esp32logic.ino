#include <WiFi.h>
#include <HTTPClient.h>
#include "secrets.h"

//const char* ssid = "";
//const char* password = "";
//remove screts.h and uncomment ssid and password

HTTPClient http;

void setup() {
  // put your setup code here, to run once:
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  http.begin("http://192.168.1.11:3000/readings");
  http.addHeader("Content-Type", "application/json");
  String body = "{\"ldr\": 42}";
  int responseCode = http.POST(body);
  http.end();
  delay(3000);
}
