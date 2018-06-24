// Y : mode of phase 2
// F : certain distance forward (phase 3)
// B : certain distance backward (phase 3)
// R : certain angle right (phase 3)
// L : certain angle left (phase 3)
// D : Demo Mode (phase 3)
// f : move forward
// b : move backwards
// r : move right
// l : move left
// T : backward right
// E : forward right
// J : backward left
// K : forward left
// S : Stop 

//bluetooth module variables:
String X;
char mode = ' ';

//Easy driving mode pins:
int ENA = 6;
int ENB = 11;
int RMotor1= 7 ; //RMotor1 is the 1st right motors pin
int RMotor2 = 8; //RMotor2 is the 2nd right motors pin
int LMotor1 = 9; //LMotor1 is the 1st left motors pin
int LMotor2 = 10; //LMotor2 is the 2nd left motors pin

//Ultrasonic Sensor Pins:
int TRIGPIN = 3;
int ECHOPIN = 5;
long distance;

//Line Follower Pins:
#define L 13
#define C 12
#define R 5
#define L2 3
#define R2 4

//Array of Sensor Values:
int sensor[3] = {0,0,0};
int extrasensor[2] = {0,0};

//Destination/Angle Value:
int value = 0;

void setup() {

  Serial.begin(9600);

  //Easy driving mode pins:
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(RMotor1, OUTPUT);
  pinMode(RMotor2, OUTPUT);
  pinMode(LMotor1, OUTPUT);
  pinMode(LMotor2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (5, INPUT);
  //Line Follower Pins:
  pinMode(L, INPUT);
  pinMode(C, INPUT);
  pinMode(R, INPUT);
  pinMode(L2, INPUT);
  pinMode(R2, INPUT);

}

//Prototypes
void Forward (int i);
void Left (int i);
void Right (int i, int n);
void Backward (int i, int n);
void BackwardRight (int i , int n);
void BackwardLeft (int i , int n);
void ForwardRight (int i , int n);
void BackwardLeft (int i , int n);
void Stop ();
long checkpath();
int Value();

void loop() {

  while(Serial.available() == 0){}
  
  while(Serial.available() > 0)
  {
    mode = Serial.read();
  }

  //PHASE ONE:
  //Ultrasonic Part:
  distance = checkpath(); //function calculating distance
  if (distance <= 25) //if distance less than 25 cm move back then stop
  {
    Backward(255);
    delay(100);
    Stop();
    Serial.println ("Back");
  }
  
  else 
  {
    if(mode == 'f')
    {      
      Forward(255);
    }
    else if(mode == 'b')
    {
      Backward(255);
    }
    else if(mode == 'l')
    {
      Left(255,0);
    }
    else if(mode == 'r')
    {
       Right(0,255);
    }
    else if(mode == 'T')
    {
      BackwardRight(255,0);
    }
    else if(mode == 'E')
    {
      ForwardRight(0,255);
    }
    else if(mode == 'J')
    { 
      BackwardLeft(255,0);
    }
    else if(mode == 'K')
    {
      ForwardLeft(0,255);
    }
    else if (mode == 'S')
    {
      Stop();
    }

    //PHASE TWO:
    else if(mode == 'Y')
    {
      sensor[0]= digitalRead(L);
      sensor[1]= digitalRead(C);
      sensor[2]= digitalRead(R);
      extrasensor[0]= digitalRead(L2);
      extrasensor[1]= digitalRead(R2);
      if((sensor[0]==0 && sensor[1]==0 && sensor[2]==1) ||(sensor[0]==0 && sensor[1]==1 && sensor[2]==1) || (sensor[0]==0 && sensor[1]==0 && sensor[2]==0 && extrasensor[0] == 1 && extrasensor[1]==0) ) {Right(0,95);}
      else if(sensor[0]==0 && sensor[1]==1 && sensor[2]==0) {Forward(75);} 
      if((sensor[0]==1 && sensor[1]==0 && sensor[2]==0)|| (sensor[0]==1 && sensor[1]==1 && sensor[2]==0) || (sensor[0]==0 && sensor[1]==0 && sensor[2]==0 && extrasensor[0] == 0 && extrasensor[1]==1) )  {Left(95,0);}
      else{}
    }
    
    //PHASE THREE:
    else if(mode == 'F')
    {
      value = Value();
      ForwardDestination(value);
    }
    else if(mode == 'B')
    {
      value = Value();
      BackwardDestination(value);
    }
    else if(mode == 'R')
    {
      value = Value();
      RightAngle(value);
    }
    else if(mode == 'L')
    {
      value = Value();
      LeftAngle(value);
    }
    else if(mode == 'D')
    {
      //DEMO MODE
    }
  }
}
 
//Functions:
void Forward (int i)
{
  
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW);  
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);   
}

void Backward (int i)
{
  
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, HIGH); 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, HIGH);  
}

void Left (int i, int n)
{
    
    analogWrite(ENA, i);
    analogWrite(ENB, n);
    
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW);
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, LOW); 
}

void Right (int i, int n)
{
    
    analogWrite(ENA, i);
    analogWrite(ENB, n);
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, LOW);
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW); 
}

void ForwardLeft (int i, int n)
{
   
    analogWrite(ENA, i);
    analogWrite(ENB, n);
    
    digitalWrite(RMotor1 ,HIGH);
    digitalWrite(RMotor2, LOW); 
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW); 
}

void ForwardRight (int i , int n)
{
  
    analogWrite(ENA, i);
    analogWrite(ENB, n);
    
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW); 
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);   
}

void BackwardLeft (int i ,int n)
{
  
    analogWrite(ENA, i);
    analogWrite(ENB, n);
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, HIGH);
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, HIGH);   
}

void BackwardRight (int i , int n)
{
  
    analogWrite(ENA, i);
    analogWrite(ENB, n);
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, HIGH); 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, HIGH);
}

void Stop () 
{
  
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, LOW); 
    
    digitalWrite(LMotor1, LOW);
    digitalWrite(LMotor2, LOW);   
}

//Ultrasonic Function:
long checkpath()
{
  
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

//Function to get the Value of the Distance/Angle
int Value () 
{

  int Value = 0;
  while(Serial.available() > 0)
  {
    Value = Value*10;
    Value = Value + (Serial.read() - '0');
    delay(10);
  }
  return Value;
}

