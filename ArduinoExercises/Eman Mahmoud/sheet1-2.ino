int led1=4;
int led2=5;
int led3=6;
int led4=7;

int ledOn=1000;
int ledOff=1000;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  
 }

void loop() {
  digitalWrite (led1,HIGH);
  delay(ledOn);
  digitalWrite(led1,LOW);
  delay(ledOff);
  digitalWrite (led2,HIGH);
  delay(ledOn);
  digitalWrite(led2,LOW);
  delay(ledOff);
  digitalWrite(led3,HIGH);
  delay(ledOn);
  digitalWrite(led3,LOW);
  delay(ledOff);
  digitalWrite(led4,HIGH);
  delay(ledOn);
  digitalWrite(led4,LOW);
  delay(ledOff);
  
  
}
