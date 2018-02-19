int ledPin =9;
int ledOn=500;
int ledOff=1500;

void setup() {
  pinMode(ledPin,OUTPUT);
  
}

void loop() {
  digitalWrite(ledPin,HIGH);
  delay(ledOn);
  digitalWrite(ledPin,LOW);
  delay(ledOff);
}
