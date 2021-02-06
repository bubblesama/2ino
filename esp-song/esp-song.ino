/**
 * Simple song from the ESP8266
 * TODO
 * 
 * 
 * 
 * 
 */
#include <ESP8266WiFi.h>
#include "wificonf.h" // contains wifiNetwork wifiPassword

int NOTES[] = {523, 587, 659, 698, 784, 880, 987, 1046, 1108};
WiFiServer server(80);

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
  server.begin();
  Serial.printf("Server started");
  espTone(testPin,NOTES[7],500);
  espTone(testPin,NOTES[0],500);
}

void loop() {
  // put your main code here, to run repeatedly:
  //musicalScale(D1);

}

// simple gamme
void musicalScale(int pin){
  for (int i=0;i<8;i++){
    espTone(pin,NOTES[i],500);
  }
}

// base method for simple sound
void espTone(uint8_t _pin, unsigned int frequency, unsigned long duration) {
  pinMode (_pin, OUTPUT );
  analogWriteFreq(frequency);
  analogWrite(_pin,500);
  delay(duration);
  analogWrite(_pin,0);
}
