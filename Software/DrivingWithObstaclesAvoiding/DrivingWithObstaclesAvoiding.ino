#define TRIGPIN 3
#define ECHOPIN 5
int RMotor1 = 7 ; //RMotor1 is the 1st right motors pin
int RMotor2 = 8; //RMotor2 is the 2nd right motors pin
int LMotor1 = 9; //LMotor1 is the 1st left motors pin
int LMotor2 = 10; //LMotor2 is the 2nd left motors pin
int ENA = 6;
int ENB = 11;
char value ;
long distance;

//Assuming that when RMotor1,LMotor1 are HIGH and RMotor2,LMotor2 are LOW the wheels move forward



void setup() {
  Serial.begin (9600);


  pinMode(ENA, OUTPUT); //Enable pins
  pinMode(ENB, OUTPUT); //Enable pins
  pinMode(RMotor1, OUTPUT);
  pinMode(RMotor2, OUTPUT);
  pinMode(LMotor1, OUTPUT);
  pinMode(LMotor2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (5, INPUT);
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
long checkpath();

void loop() {
   // put your main code here, to run repeatedly:

    

value=Serial.read(); 

distance = checkpath(); //function calculating distance
   

   if (distance <= 25) //if distance less thant 25 cm move back then stop
              {

                  Backward (255);

                     delay(100);

                   Stop (); 
                  Serial.println ("back");
 
               }
   
     

 else {
  
     
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
   

    else if ( value == 'S' )
        {
              Stop ();
        }
 }

 }
 
 void Forward (int i) {
    analogWrite(ENA, i); // to set the speed of the 1st motor by i  from 0-255
    analogWrite(ENB, i);  // to set the speed of the 2nd motor by i ..
    
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW);  // setting the motors to go backward 
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);   // setting the motors to go backward   
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
  long checkpath() {
  digitalWrite(TRIGPIN, LOW);

  delayMicroseconds(2);

  digitalWrite(TRIGPIN, HIGH);

  delayMicroseconds(10);

  digitalWrite(TRIGPIN, LOW);
  
  long duration = pulseIn(ECHOPIN, HIGH);

  long distance = duration / 58.8235294 ;

  Serial.print(distance);

  Serial.println(" cm");
  return distance;
  }

