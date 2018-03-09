int RMotor1= 1 ; //RMotor1 is the 1st right motors pin
int RMotor2 = 2; //RMotor2 is the 2nd right motors pin
int LMotor1 = 3; //LMotor1 is the 1st left motors pin
int LMotor2 = 4; //LMotor2 is the 2nd left motors pin
int ENA = 4;
int ENB = 4;
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
   
   Serial.println(value);
   
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
   

else if ( value == 'K')
   { 
    BackwardRight (255,120);
    }
  
else if ( value == 'M')
   {
    ForwardRight (120,255);
    }

    
else if ( value == 'J')
   {
    BackwardLeft (255,120);
    }

else if ( value == 'C')
  {
  BackwardRight (120,255);
  }
   

else if ( value == 'S' )
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
  }
  void Left (int i) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, i);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, LOW);   // setting the motors to go backward   
  }
  void Right (int i) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, i);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, LOW);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);   // setting the motors to go backward   
  }
  void ForwardLeft (int i , int n) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, n);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1 ,HIGH);
    digitalWrite(RMotor2, LOW);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);   // setting the motors to go backward   
  }
  void ForwardRight (int i , int n) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, n);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);   // setting the motors to go backward   
  }
  void BackwardLeft (int i ,int n) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, n);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, HIGH);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, HIGH);   // setting the motors to go backward   
  }
  void BackwardRight (int i , int n) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, n);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, HIGH);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, HIGH);   // setting the motors to go backward   
  }
  void Stop () {
    analogWrite(ENA, 255); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, 255);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, LOW);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, LOW);   // setting the motors to go backward   
  }
