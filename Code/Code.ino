char order;
int A1 = ; //A1 is the 1st right motors pin
int B1 = ; //B1 is the 2nd right motors pin
int A2 = ; //A2 is the 1st left motors pin
int B2 = ; //B2 is the 2nd left motors pin

//Assuming that when A1,A2 are HIGH and B1,B2 are LOW the wheels move forward



void setup() {
  pinMode(ENA, OUTPUT); //Enable pins
  pinMode(ENB, OUTPUT); //Enable pins
  pinMode(A1, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B2, OUTPUT);
}

void loop() {
   // put your main code here, to run repeatedly:
 }
 // salma tarek
void Left () {
  //function to turn the car to the left (sharp angle)
  analogWrite(ENA, 255); //adjusting the speed to the highest value
  analogWrite(ENB, 255); //adjusting the speed to the highest value
  //turning the right motors on
  digitalWrite(A1, HIGH); 
  digitalWrite(B1, LOW);
  //turning the left motors off
  digitalWrite(A2, LOW);
  digitalWrite(B2, LOW);  
}
// Eman Mahmoud
//function to turn the car to the left ( sharp angle )
void Left (){
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(A1, HIGH );
  digitalWrite(B1,LOW );
  digitalWrite(A2,LOW );
  digitalWrite(B2, LOW);

//function to turn the car to the Right (sharp angle)
void Right ()
{
analogWrite(ENA, 255);
analogWrite(ENA, 255);
digitalWrite(A2, HIGH);
digitalWrite(B2, LOW);
digitalWrite(A1, LOW);
digitalWrite(B1, LOW);
}

void Forward ()
{
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  //turning the two front motors A1,A2 ON
  digitalWrite(A1, HIGH);
  digitalWrite(B1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(B2, LOW);
}
 


void Backward ()
{
 
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  
  digitalWrite(A1,LOW);
  digitalWrite(B1,HIGH);
  digitalWrite(A2,LOW);
  digitalWrite(B2,HIGH);
  
}
void Forward_Right ()
{
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  //turning the front-left motor and the back-right motor ON
  digitalWrite(A1, LOW);
  digitalWrite(B1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(B2, LOW);
}
//mariam elsayed 
  void Forward_left()
  {
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
  //forward left turning the car slightly to the left 
    // right motors on while left are off
     digitalWrite(A1, HIGH);
     digitalWrite(B1, LOW); 
     digitalWrite(A2, LOW);
     digitalWrite(B2, LOW);

