#include "TimerOne.h"
int Pin = 2;
unsigned int counter = 0;
int ENA = 6;
int ENB = 11;
int RMotor1= 7 ; //RMotor1 is the 1st right motors pin
int RMotor2 = 8; //RMotor2 is the 2nd right motors pin
int LMotor1 = 9; //LMotor1 is the 1st left motors pin
int LMotor2 = 10; //LMotor2 is the 2nd left motors pin

void docount()  // counts from the speed sensor
{
  counter++;  // increase +1 the counter value
}
void Forward (int i)
{
  
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    
    digitalWrite(RMotor1, HIGH);
    digitalWrite(RMotor2, LOW);  
    
    digitalWrite(LMotor1, HIGH);
    digitalWrite(LMotor2, LOW);   
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

void setup() {
  Serial.begin(9600);
  digitalPinToInterrupt(2);
  attachInterrupt(0, docount, RISING);  // increase counter when speed sensor pin goes High
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(RMotor1, OUTPUT);
  pinMode(RMotor2, OUTPUT);
  pinMode(LMotor1, OUTPUT);
  pinMode(LMotor2, OUTPUT);
}

void loop() {
  Serial.println(counter); 
  Forward(150);
  if(counter >= 100)
  {
    Stop();
    Serial.println(counter);
    counter = 0;
    Serial.println(counter);
    delay (4000);
  }
}


