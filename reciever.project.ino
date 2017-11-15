#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);

const byte rxAddr[6] = "00001";

void setup()
{
  pinMode(4,OUTPUT);
  while (!Serial);
  Serial.begin(9600);
  
  radio.begin();
  radio.openReadingPipe(0, rxAddr);
  
  radio.startListening();
}

void loop()
{
  if (radio.available())
  {
    float numLEDSLit=0;
    if(radio.read(&numLEDSLit, sizeof(numLEDSLit)),Serial.println("Signal recieved!!!"));
    Serial.println(numLEDSLit);
    if(numLEDSLit>2.8)
    {
    digitalWrite(4,HIGH);
    }
    else
    {
    digitalWrite(4,LOW);
    }
  }
  
}
