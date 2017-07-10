#include <LiquidCrystal.h>
#include <Servo.h> 

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(5,       //RS
                  4,       //E
                  3,       //D4
                  2,       //D5
                  1,       //D6
                  0);      //D7
                  
Servo ServoB;  
Servo Servo1;  
Servo Servo2;  
Servo Servo3;  
Servo Servo4; 
Servo ServoG;  

void setup() 
{
  pinMode(6, INPUT);           // pone el pin como entrada
  digitalWrite(6, HIGH);       // activa la resistencia pullup

  ServoB.attach(13);  
  Servo1.attach(12);
  Servo2.attach(11);
  Servo3.attach(10);
  Servo4.attach(9);
  ServoG.attach(8);
  
  lcd.begin(16, 2);
  lcd.print(" SB S1 S2 S3 SG");
}

void MoveServo(Servo sServo, int nActualPosition, int nNewPosition, int x)
{
  while(nActualPosition != nNewPosition)
  {    
     if(nActualPosition < nNewPosition)
       nActualPosition ++;
     else
       nActualPosition--;
       
    sServo.write(nActualPosition);
    
    lcd.setCursor(x, 1);
    lcd.print("   ");
    lcd.setCursor(x, 1);
    lcd.print(nActualPosition);
    delay(30);  
  }  
}

int nSecuencia = 0;

void loop() {
  
    if(digitalRead(6))
    {    
      MoveServo(ServoB, 70, 110, 1);
      delay(1000);   
      MoveServo(Servo1, 70, 110, 4);
      delay(1000);   
      MoveServo(Servo2, 70, 110, 7);
      delay(1000);   
      MoveServo(Servo3, 70, 110, 10);
      delay(1000);   
      MoveServo(ServoG, 70, 110, 13);
      delay(3000); 
      MoveServo(ServoB, 110, 70, 1);
      delay(1000);   
      MoveServo(Servo1, 110, 70, 4);
      delay(1000);   
      MoveServo(Servo2, 110, 70, 7);
      delay(1000);   
      MoveServo(Servo3, 110, 70, 10);
      delay(1000);   
      MoveServo(ServoG, 110, 70, 13);
      delay(3000);      
    }    
}

