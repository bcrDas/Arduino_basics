
#include<LiquidCrystal.h>
LiquidCrystal lcd{12,11,5,4,3,2};
void setup() {
  lcd.begin(16,2);
  lcd.print("ahmad");
  pinMode(7,OUTPUT);
  pinMode(8,INPUT);
 Serial.begin(9600);
}

void loop() {
  digitalWrite(7,LOW);
  delayMicroseconds(10);
  digitalWrite(7,HIGH);
  delayMicroseconds(10);
  digitalWrite(7,LOW);
  delayMicroseconds(6);
  int duration=pulseIn(8,HIGH);
  int distance=duration*(0.034/2);
  lcd.setCursor(0,1);
  lcd.print("Distance=");
  lcd.print(distance); 
  delay(3000);
}
