int RMotor1= 10 ; //RMotor1 is the 1st right motors pin
int RMotor2 = 7; //RMotor2 is the 2nd right motors pin
int LMotor1 = 5; //LMotor1 is the 1st left motors pin
int LMotor2 = 6; //LMotor2 is the 2nd left motors pin
int ENA = 11;
int ENB = 3;
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
void ForwardLeft (int i , int n) ;
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
   
else if ( value == 'N')
{ 
  ForwardLeft (255,120);
}
  
else if ( value == 'M')
{
  ForwardRight (120,255);
}
    
else if ( value == 'P')
{
  BackwardLeft (255,120);
}

else if ( value == 'O')
{
  BackwardRight (120,255);
}
   
else if ( value == 'S' )
{
  Stop ();
}
}
 
 void Forward (int i)
 {
    analogWrite(ENA, i); //setting the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, i);  //setting the speed of the 2nd motor by i from 0-255
    //Setting the Motors to go forward:
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW);
    //Setting the motors to go forward
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);
    Serial.println('F');   
  }
 
 void Backward (int i)
 {
    analogWrite(ENA, i); //setting the speed of the 1st motor by i from 0-255
    analogWrite(ENB, i);  //setting the speed of the 2nd motor by i from 0-255
    //Setting the motors to go backwards:
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, HIGH); 
    //Setting the motors to go backwards:
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, HIGH);   
  }

  void Left (int i)
  {
    analogWrite(ENA, i); //setting the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, i);  //setting the speed of the 2nd motor by i from 0-255
    //setting the motors to go forward
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW);
    //stopping the motors
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, LOW);   
  }

  void Right (int i) 
  {
    analogWrite(ENA, i); //setting the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, i);  //setting the speed of the 2nd motor by i from 0-255
    //stopping the motors
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, LOW);
    //setting the motors to go forward
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);   
  }

  void ForwardLeft (int i , int n) {
    analogWrite(ENA, i); //setting the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, n);  //setting the speed of the 2nd motor by n from 0-255
    //speed n will be lower than speed i
    digitalWrite(RMotor1 ,HIGH);
    digitalWrite(RMotor2, LOW);
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);   
  }

  void ForwardRight (int i , int n) {
    analogWrite(ENA, i); //setting the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, n);  //setting the speed of the 2nd motor by n from 0-255
    //speed i will be lower than speed n
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW); 
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);  
  }

  void BackwardLeft (int i ,int n) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, n);  // to set the speed of the 2nd motor by n from 0-255
    //speed n will be lower than speed i
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, HIGH);
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, HIGH);  
  }

  void BackwardRight (int i , int n) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, n);  // to set the speed of the 2nd motor by i ..
    //speed i will be lower than n
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, HIGH);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, HIGH);   // setting the motors to go backward   
  }

  void Stop () {
    //stopping both motors
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, LOW); 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, LOW);   
  }
