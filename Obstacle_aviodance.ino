
//pwm_motor_1 and pwm_motor_2 pins defined as output in arduino is  connected to the pwm pin on driver board, ther are 2 such pin on driver board 1 for each motor
//dir_motor_1 and dir_motor_2 pins defined as output in arduino is  connected to the dir oin on driver board, ther are 2 such pin on driver board 1 for each motor

int ch1; // ye receiver ka channnel 1 ka value he
int ch2; // ye receiver ka channnel 2 ka value he


int updown =0; // ye variable forward aur backward updown kitna hoga yo store karta he
int prevupdown =0;
int prevside =0;
int side=0;; // sideing Factor

int pwm_motor_1 = 3;  //pin 3 of arduino for pwm control of motor 1
int pwm_motor_2 = 11;  //pin 11 of arduino for pwm control of motor 2
int dir_motor_1 = 12;  //direction control pin on arduino for motor 1
int dir_motor_2 = 13;  //direction control pin on arduino for motor 2

void setup() {
  pinMode(5, INPUT); // pin 5 of arduino is input form receiver channel 1 
  pinMode(6, INPUT); // pin 6 of arduino is input form receiver channel 1

  Serial.begin(9600); // Pour a bowl of Serial (for debugging)

  pinMode(pwm_motor_1, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_motor_2, OUTPUT);
  pinMode(dir_motor_1, OUTPUT);
  pinMode(dir_motor_2, OUTPUT);

  analogWrite(pwm_motor_1, 0);  
  analogWrite(pwm_motor_2, 0);
}

void loop() 
{
  
  ch1 = pulseIn(5, HIGH, 25000); // Read the pulse width of  
  updown = map(ch1, 1050,2000, -255, 255); //center over zero
  updown = constrain(updown, -255, 255);

  ch2 = pulseIn(6, HIGH, 25000); // Read the pulse width of  
  side = map(ch2, 1000,2000, -255, 255); //center over zero
  side = constrain(side, -255, 255);

  if(updown>50)
  {
     digitalWrite(dir_motor_1, 1);
     digitalWrite(dir_motor_2, 1);
     analogWrite(pwm_motor_1, updown); 
     analogWrite(pwm_motor_2, updown);
     Serial.print("up"); //Serial debugging stuff
     Serial.println(updown);

  }
  else if(updown<-50 && updown > -250)
  {
  digitalWrite(dir_motor_1, 0);
  digitalWrite(dir_motor_2, 0);
  updown=abs(updown);
  analogWrite(pwm_motor_1, updown); 
  analogWrite(pwm_motor_2, updown);
  Serial.print("down"); //Serial debugging stuff
  Serial.println(updown);
  }
  
 else if(side>50)
  {
     digitalWrite(dir_motor_1, 1);
     digitalWrite(dir_motor_2, 0);
     analogWrite(pwm_motor_1, side); 
     analogWrite(pwm_motor_2, side);
     Serial.print("left"); //Serial debugging stuff
     Serial.println(side);
  }
 else if(side<-50 && side > -215)
  {
     side=abs(side); 
     digitalWrite(dir_motor_1, 0);
     digitalWrite(dir_motor_2, 1);
     analogWrite(pwm_motor_1, side); 
     analogWrite(pwm_motor_2, side);
     Serial.print("right"); //Serial debugging stuff
     Serial.println(side);
  }

  else
  {
  digitalWrite(dir_motor_1, 1);
  digitalWrite(dir_motor_2, 1);
  analogWrite(pwm_motor_1, 0);  
  analogWrite(pwm_motor_2, 0);
  Serial.print("stop"); //Serial debugging stuff
  Serial.println(updown);
  }
  
}
