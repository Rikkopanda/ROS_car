
// Code 1 : Sending Text (Transmitter)
// Library: TMRh20/RF24 (https://github.com/tmrh20/RF24/)

#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include "../config.h"

RF24 radio(D_CE, D_CS); // CE, CSN
const byte address[10] = "ADDRESS01";

void setup() {

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
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.println("Hello from Transmitter");
};

void loop() {
  const char txt[] = "Hello World";
  Serial.printf("transmitting message: %s\n", txt);
  if (radio.write(&txt, sizeof(txt)) == true)
    Serial.println("payload delivered succesfully and acknowledgement was sent back(ACK packet received)");
  else
    Serial.println("payload sent but NO acknowledgement was sent back(no ACK packet received)");

  delay(1000);
};
