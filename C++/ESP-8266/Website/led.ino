#include <ESP8266WiFi.h>
#include "web.h"

#ifndef STASSID
#define STASSID "LABKOM1B"
#define STAPSK "password"
#endif

#define led1 D4
#define led2 D5
#define led3 D6

//buat status lampu
bool statusled1 = false;
bool statusled2 = false;
bool statusled3 = false;

const char* ssid = STASSID;
const char* password = STAPSK;

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  // prepare LED
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led2, LOW);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print(F("Connecting to "));
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));

  // Start the server
  server.begin();
  Serial.println(F("Server started"));

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.accept();
  if (!client) { return; }
  Serial.println(F("new client"));

  client.setTimeout(5000);  // default is 1000

  String req = client.readStringUntil('\r');
  Serial.println(F("request: "));
  Serial.println(req);
  
  if(req.indexOf("/led1/1") != -1){
    digitalWrite(led1, HIGH);
    statusled1 = true;
  } else if(req.indexOf("/led1/0") != -1){
    digitalWrite(led1, LOW);
    statusled1 = false;
  } else if(req.indexOf("/led2/1") != -1){
    digitalWrite(led2, HIGH);
    statusled2 = true;
  } else if(req.indexOf("/led2/0") != -1){
    digitalWrite(led2, LOW);
    statusled2 = false;
  } else if(req.indexOf("/led3/1") != -1){
    digitalWrite(led3, HIGH);
    statusled3 = true;
  } else if(req.indexOf("/led3/0") != -1){
    digitalWrite(led3, LOW);
    statusled3 = false;
  }

  while(client.available()) {
  client.read();
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();                 // baris kosong pemisah header & body
  client.print(FPSTR(MAIN_PAGE));   // kirim isi halaman dari PROGMEM

  client.flush();

}