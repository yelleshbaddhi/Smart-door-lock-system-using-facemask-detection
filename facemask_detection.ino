#include <LiquidCrystal.h>
#include <Servo.h>
const int buzzer = 10; 
int incomingByte;      
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int pos = 0;   
int val;
Servo myservo;
int countH=0;
int countL=0;

  
void setup() {
  Serial.begin(9600);
  myservo.attach(5); 
  pinMode(buzzer, OUTPUT);
  pinMode(13,OUTPUT);  
  pinMode(12,OUTPUT);
  lcd.begin(16, 2); 
  myservo.write(0);                      
}

void loop() {
  
  if (Serial.available() > 0) {   
    incomingByte = Serial.read();
    if (incomingByte == 'H') { 
      digitalWrite(buzzer,HIGH);
  
           myservo.write(90);
           
          
         
      
      
     //noTone(buzzer);
 
     lcd.clear();
     lcd.setCursor(0, 0);    
     lcd.print("Mask Detected");      
    }
    if (incomingByte == 'L') {
      //tone(buzzer,450);
      
   digitalWrite(buzzer,LOW);
 
       myservo.write(0);
          
         
          
          
      lcd.clear();
      lcd.setCursor(0, 0);    
     lcd.print("Please Wear Mask");
    }
    
   
  }
  
}

  
