/**
 * Simple song from the ESP8266
 * TODO
 * 
 * 
 * 
 * 
 */

int notes[] = {523, 587, 659, 698, 784, 880, 987, 1046, 1108};

int testPin = D1;

void setup() {
  // put your setup code here, to run once:
  pinMode(testPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  musicalScale(D1);

}

// simple gamme
void musicalScale(int pin){
  for (int i=0;i<8;i++){
    espTone(pin,notes[i],500);
  }
}

// base method for simle sound
void espTone(uint8_t _pin, unsigned int frequency, unsigned long duration) {
  pinMode (_pin, OUTPUT );
  analogWriteFreq(frequency);
  analogWrite(_pin,500);
  delay(duration);
  analogWrite(_pin,0);
}
