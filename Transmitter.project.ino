

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);

const byte rxAddr[6] = "00001";

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  
  radio.stopListening();
}

void loop()
{
  float reading  = analogRead(A1);
  float numLEDSLit = reading / 57;  //1023 / 9 / 2
  Serial.println(numLEDSLit);
  radio.write(&numLEDSLit, sizeof(numLEDSLit));
  if(radio.write(&numLEDSLit, sizeof(numLEDSLit)),Serial.println("Transmittion done!!!"));   
  else
  Serial.println("Transmittion failed!!!");
  delay(1000);
}
