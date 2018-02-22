int led=8;
int ledOn=500;
int ledOff=1500;

void setup() {
  pinMode(led,OUTPUT);
  
 }

void loop() {
  digitalWrite (led,HIGH);
  delay(ledOn);
  digitalWrite(led,LOW);
  delay(ledOff);
}
