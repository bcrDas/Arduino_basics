

String voice;
const int led1 = 2; 
const int led2 = 3; 
const int led3 = 4;
const int led4 = 5; 
const int led5 = 6; 
const int led7 = 8; 




 void setup()
 {
    
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led7, OUTPUT);
  digitalWrite(led7,HIGH);
  
 }



 void loop() 
  { 
    
  while (Serial.available())
   {  
     
    delay(10); 
    char c = Serial.read(); 
    if (c == '#') {break;} 
    voice += c; 
     
   } 
   
  if (voice.length() > 0)
   {
     
       Serial.println(voice);
       if(voice == "*all on")
         {
           
          allon();
         
         }  
       
       else if(voice == "*all of")
         {
            
          alloff();
          
         } 
 
       else if(voice == "*TV on"){digitalWrite(led1, HIGH);}
       else if(voice == "*relay on") {digitalWrite(led7,LOW);}
       else if(voice == "*fan on") {digitalWrite(led2, HIGH);}
       else if(voice == "*computer on") {digitalWrite(led3, HIGH);}
       else if(voice == "*bedroom lights on") {digitalWrite(led4, HIGH);}
       else if(voice == "*bathroom lights on") {digitalWrite(led5, HIGH);}
  
       else if(voice == "*TV off") {digitalWrite(led1, LOW);}
       else if(voice == "*relay of") {digitalWrite(led7, HIGH);}
       else if(voice == "*fan of") {digitalWrite(led2, LOW);}
       else if(voice == "*computer of") {digitalWrite(led3, LOW);}
       else if(voice == "*bedroom lights of") {digitalWrite(led4, LOW);}
       else if(voice == "*bathroom lights of") {digitalWrite(led5, LOW);}

       voice="";
       
   } 
   
  } 



 void allon()
  {
    
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
     digitalWrite(led5, HIGH);
       
   }
  
  
  
 void alloff()
  {
    
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
     digitalWrite(led5, LOW);
        
  } 
