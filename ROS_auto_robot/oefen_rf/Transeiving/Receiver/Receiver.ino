
// Code 1 : Sending Text (Receiver)
// Library: TMRh20/RF24 (https://github.com/tmrh20/RF24/)

#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

#include "../config.h"

RF24 radio(D_CE, D_CS); // CE, CSN
const byte address[10] = "ADDRESS01";

void setup()
{
  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS: ");
  Serial.println(SS);
  // SPI.begin(D_SCK, D_MISO, D_MOSI, D_CS);
  Serial.begin(9600);
  if (radio.begin() == true)
    Serial.println("esp32 established communication with radio");
  else
    Serial.println("esp32 failed to communicate with radio");


  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(D_IQR_INTERRUPT, INPUT_PULLDOWN);
  Serial.println("Hello from Receiver");
};

void loop() {
  if (radio.available()) {
    char txt[32] = "";
    radio.read(&txt, 32);
    Serial.printf("Receiver message read: (%s)\n", txt);
    delay(1000);
  };
};
