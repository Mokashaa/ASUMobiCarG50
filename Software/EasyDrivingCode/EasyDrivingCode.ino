int ENA =6;
int RMotor1= 7 ; //RMotor1 is the 1st right motors pin
int RMotor2 = 8; //RMotor2 is the 2nd right motors pin
int LMotor1 = 9; //LMotor1 is the 1st left motors pin
int LMotor2 = 10; //LMotor2 is the 2nd left motors pin
int ENB =11 ;
char value ;

//Assuming that when RMotor1,LMotor1 are HIGH and RMotor2,LMotor2 are LOW the wheels move forward



void setup() {
  Serial.begin (9600);


  pinMode(ENA, OUTPUT); //Enable pins
  pinMode(ENB, OUTPUT); //Enable pins
  pinMode(RMotor1, OUTPUT);
  pinMode(RMotor2, OUTPUT);
  pinMode(LMotor1, OUTPUT);
  pinMode(LMotor2, OUTPUT);
}

//Prototypes
void Forward (int i);
void Left (int i);
void Right (int i) ;
void Backward (int i) ;
void BackwardRight (int i , int n) ;
void BackwardLeft (int i , int n) ;
void ForwardRight (int i , int n) ;
void BackwardLeft (int i , int n) ;
void Stop () ;

void loop() {
   // put your main code here, to run repeatedly:
   

   value=Serial.read(); 
   
if(value == 'F')
   {
     Forward (255);
    }

else if ( value == 'B')
    {
     Backward (255);
     }

else if ( value == 'L')
{
  Left(255) ;
  }

else if ( value == 'R')
{
  Right(255);
  }
   

else if ( value == 'T')
   { 
    BackwardRight (255,0);
    }
  
else if ( value == 'E')
   {
    ForwardRight (0,255);
    }

    
else if ( value == 'J')
   {
    BackwardLeft (255,0);
    }

else if ( value == 'K')
  {
  ForwardLeft (0,255);
  }
   

else if (value == 'S')
  {
    Stop ();
    }
 }
 
 void Forward (int i) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, i);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);   // setting the motors to go backward
    Serial.println('F');   
  }
 
 
 void Backward (int i) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, i);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, HIGH);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, HIGH);   // setting the motors to go backward   
        Serial.println('B');   

  }
  void Left (int i) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, i);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, LOW);   // setting the motors to go backward   
        Serial.println('L');   

  }
  void Right (int i) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, i);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, LOW);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);   // setting the motors to go backward   
        Serial.println('R');   

  }
  void ForwardLeft (int i , int n) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, n);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1 ,HIGH);
    digitalWrite(RMotor2, LOW);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);   // setting the motors to go backward   
        Serial.println('K');   

  }
  void ForwardRight (int i , int n) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, n);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);   // setting the motors to go backward   
        Serial.println('E');   

  }
  void BackwardLeft (int i ,int n) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, n);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, HIGH);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, HIGH);   // setting the motors to go backward   
        Serial.println('J');   

  }
  void BackwardRight (int i , int n) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, n);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, HIGH);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, HIGH);   // setting the motors to go backward   
        Serial.println('T');   

  }
  void Stop () {
    analogWrite(ENA, 255); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, 255);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, LOW);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, LOW);   // setting the motors to go backward   
        Serial.println('S');   

  }
