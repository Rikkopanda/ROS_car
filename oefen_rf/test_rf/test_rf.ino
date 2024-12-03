
#include "Arduino.h"
#define BAUDRATE 9600

/* Setup function--runs once at startup. */
void setup() {
  Serial.begin(BAUDRATE);
  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS: ");
  Serial.println(SS); 
}

void loop() {

  while (Serial.available() > 0)
  {
    // Read the next character
    char chr = Serial.read();
    delay(10);
  }
}