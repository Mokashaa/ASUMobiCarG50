// O=31 : mode of phase 2
// F=22 : certain distance forward (phase 3)
// B=18 : certain distance backward (phase 3)
// R=34 : certain angle right (phase 3)
// L=28 : certain angle left (phase 3)
// D=20 : Demo Mode (phase 3)
// f=54 : move forward
// b=50 : move backwards
// r=66 : move right
// l=60 : move left
// s=67 : Stop 

//bluetooth module variables:
unsigned int reading = 0;
//pulses counter
unsigned int counter = 0;
//Easy driving mode pins:
int ENA = 5;
int ENB = 10;
int RMotor1= 6 ; //RMotor1 is the 1st right motors pin
int RMotor2 = 7; //RMotor2 is the 2nd right motors pin
int LMotor1 = 9; //LMotor1 is the 1st left motors pin
int LMotor2 = 8; //LMotor2 is the 2nd left motors pin

//Ultrasonic Sensor Pins:
// int TRIGPIN = 3;
// int ECHOPIN = 5;
//long distance;

//Line Follower Pins:
#define L 11
#define C 12
#define R 13
#define L2 3
#define R2 4

//Array of Sensor Values:
int sensor[3] = {0,0,0};
int extrasensor[2] = {0,0};

//Destination/Angle Value:
int Pin = 2;
int stateNew = 0;
int stateOld = 0;
int PulsesNeeded = 0;

void setup() {

  Serial.begin(9600);

  //Easy driving mode pins:
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(RMotor1, OUTPUT);
  pinMode(RMotor2, OUTPUT);
  pinMode(LMotor1, OUTPUT);
  pinMode(LMotor2, OUTPUT);
  // pinMode (3, OUTPUT);
  // pinMode (5, INPUT);
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
int Reading ();
void BackwardDistance (int a);
void ForwardDistance (int a);
void RightAngle (int a);
void LeftAngle (int a);

void loop() {
  
 reading = Reading ();
 Serial.println(reading);
 
 //PHASE ONE:
 //Ultrasonic Part:
 //distance = checkpath(); //function calculating distance
 //if (distance <= 25) //if distance less than 25 cm move back then stop
 //  {
 //    Backward(255);
 //    delay(100);
 //    Stop();
 //  }
  
 // else 
 // {
    if(reading == 54)
    {      
      Forward(120);
    }
    else if(reading == 50)
    {
      Backward(120);
    }
    else if(reading == 60)
    {
      Left(100,100);
    }
    else if(reading == 66)
    {
       Right(100,100);
    }
    else if (reading == 67)
    {
      Stop();
    }

    //PHASE TWO:
    else if(reading == 31)
    {
      sensor[0]= digitalRead(L);
      sensor[1]= digitalRead(C);
      sensor[2]= digitalRead(R);
      extrasensor[0]= digitalRead(L2);
      extrasensor[1]= digitalRead(R2);
      if((sensor[0]==0 && sensor[1]==0 && sensor[2]==1) ||(sensor[0]==0 && sensor[1]==1 && sensor[2]==1) || (sensor[0]==0 && sensor[1]==0 && sensor[2]==0 && extrasensor[0] == 1 && extrasensor[1]==0) ) {Right(0,95);}
      else if(sensor[0]==0 && sensor[1]==1 && sensor[2]==0) {Forward(75);} 
      else if((sensor[0]==1 && sensor[1]==0 && sensor[2]==0)|| (sensor[0]==1 && sensor[1]==1 && sensor[2]==0) || (sensor[0]==0 && sensor[1]==0 && sensor[2]==0 && extrasensor[0] == 0 && extrasensor[1]==1) )  {Left(95,0);}
      else{}
    }
    
    //PHASE THREE:
    else if(reading > 22000 && reading < 23000)
    {
      unsigned int  value = reading - 22000;
      ForwardDistance(value);
    }
    
    else if(reading > 18000 && reading < 19000 )
    {
     unsigned int value = reading - 18000;
     BackwardDistance(value);
    }
    
    else if(reading > 34000 && reading < 35000)
    {
     unsigned int value = reading - 34000;
     RightAngle(value);
    }
    
    else if(reading > 28000 && reading < 29000)
    {
     unsigned int  value = reading - 28000;
     LeftAngle(value);
    }
    
  //  else if(reading == 20)
  //  {
      //DEMO MODE
  //  }
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
    
    digitalWrite(RMotor1, LOW);
    digitalWrite(RMotor2, HIGH);
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW); 
}

void Right (int i, int n)
{
    
    analogWrite(ENA, i);
    analogWrite(ENB, n);
    
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW);
    
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
/*long checkpath()
{
  
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  
  long duration = pulseIn(ECHOPIN, HIGH);
  long distance = duration / 58.8235294 ;
  
  return distance;
}*/

//Function to get the Value of the Distance/Angle
int Reading () {
  
  unsigned int value = 0;
  String X = "";
  String Number = "";
  
  while(Serial.available() == 0) {}
  
  while(Serial.available() > 0)
  {
    X = X + (Serial.read() - '0') ;    
    delay(2);
  }
  
  for ( int i = 0 ; i <= 4 ; i++)
  {
    if(X[i] == '-')
    break;
    Number = Number + X[i];
  }
    
  value = Number.toInt();
  return value;
}

void ForwardDistance (int a) {
     int PulsesNeeded = a*0.9794*2;
     PulsesNeeded = ceil(PulsesNeeded);
     counter = 0;
     while(counter < PulsesNeeded ){
      Forward(80);
      stateNew = digitalRead(Pin);
      if (stateNew != stateOld){
        stateOld = stateNew;
        counter ++;
        } 
      } 
      Stop();
}


void BackwardDistance (int a) {
     int PulsesNeeded = a*0.9794*2;
     PulsesNeeded = ceil(PulsesNeeded);
     counter = 0;
     while(counter < PulsesNeeded ){
      Backward(80);
      stateNew = digitalRead(Pin);
      if (stateNew != stateOld){
        stateOld = stateNew;
        counter ++;
        } 
      } 
      Stop();
}

void RightAngle (int a) {
     int zawya = ((22/7)*a)/180;
     PulsesNeeded = (zawya*9*2)*0.9794*2;
     PulsesNeeded = ceil(PulsesNeeded);
     counter = 0;
     while(counter < PulsesNeeded ){
      Right(100,100); 
      stateNew = digitalRead(Pin);
      if (stateNew != stateOld){
        stateOld = stateNew;
        counter ++;
        }
      } 
      Stop(); 
}

void LeftAngle (int a) {
     int zawya = ((22/7)*a)/180;
     PulsesNeeded = (zawya*9*2)*0.9794*2;
     PulsesNeeded = ceil(PulsesNeeded);
     counter = 0;
     while(counter < PulsesNeeded ){
      Left(100,100); 
      stateNew = digitalRead(Pin);
      if (stateNew != stateOld){
        stateOld = stateNew;
        counter ++;
        }
      } 
      Stop(); 
}

