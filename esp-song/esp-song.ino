/**
 * Simple song from the ESP8266
 * TODO
 * 
 * 
 * 
 * 
 */
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "wificonf.h" // contains wifiNetwork wifiPassword
#include "espsong_html.h" // contains static pages

int NOTES[] = {523, 587, 659, 698, 784, 880, 987, 1046, 1108};

ESP8266WebServer server(80);

int testPin = D1;

void setup() {
  // put your setup code here, to run once:
  pinMode(testPin, OUTPUT);

  // wifi startup
  Serial.begin(115200);
  delay(10);
  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(wifiNetwork);
  WiFi.begin(wifiNetwork, wifiPassword);
  while (WiFi.status() != WL_CONNECTED) {
    delay(400);
    Serial.print(".");
    espTone(testPin,NOTES[0],100);
  }
  Serial.println("");
  Serial.printf("WiFi connected,local IP %s in a web browser\n", WiFi.localIP().toString().c_str());
  server.on("/", serveEmptyPromise);
  server.on("/chirp", serveDefaultMusicalScale);
  server.begin();
  espTone(testPin,NOTES[7],500);
  Serial.printf("Server started");
}

void loop() {
  server.handleClient();
}

// simple gamme
void musicalScale(int pin){
  for (int i=0;i<8;i++){
    espTone(pin,NOTES[i],500);
  }
}

void serveDefaultMusicalScale(){
  server.send(200, "text/html",getChirpHtml());
  musicalScale(D1);
}

void serveEmptyPromise(){
  server.send(200, "text/html",getEmptyHtml());
}


// prepare a web page to be send to a client (web browser)
String getChirpHtml(){
  String htmlPage = "<!DOCTYPE HTML><html><body>Chirp ♫</body></html>\r\n";
  return htmlPage;
}

// prepare a web page to be send to a client (web browser)
String getEmptyHtml(){
  return rootPageHtml;
}

// base method for simple sound
void espTone(uint8_t _pin, unsigned int frequency, unsigned long duration) {
  pinMode (_pin, OUTPUT );
  analogWriteFreq(frequency);
  analogWrite(_pin,500);
  delay(duration);
  analogWrite(_pin,0);
}
