
int led = 3;
int outPin1 = 5;     //motor1
int outPin2 = 6;    //motor1

int outPin4 = 11;   //motor2
int outPin3 = 12;   //motor2
char bt = 0;     

void setup() {
  // put your setup code here, to run once:
  // besmallah
  Serial.begin(9600);
  
  pinMode(outPin1,OUTPUT);
  pinMode(outPin2,OUTPUT);
  pinMode(outPin3,OUTPUT);
  pinMode(outPin4,OUTPUT);
  
pinMode(led,OUTPUT);
  
}

void loop() {
  // put your mai if (Serial.available() > 0)
   if (Serial.available() > 0)
  {
    bt = Serial.read();
    digitalWrite(led, 1);n code here, to run repeatedly:
if (bt == 'R')    //right
    {
      digitalWrite(outPin1,HIGH);
      digitalWrite(outPin2,LOW);
      digitalWrite(outPin3,LOW);
      digitalWrite(outPin4,LOW);
    } else if (bt == 'G')    //backward left
    {
      digitalWrite(outPin1,LOW);
      digitalWrite(outPin2,LOW);
      digitalWrite(outPin3,HIGH);
      digitalWrite(outPin4,LOW);
    }

   }
}
