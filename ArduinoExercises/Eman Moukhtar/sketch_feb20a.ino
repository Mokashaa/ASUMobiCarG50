int redLED=9;
int yellowLED=10;
int greenLED=11;

void setup() {
  pinMode(redLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  pinMode(greenLED,OUTPUT);

}

void loop() {
  digitalWrite(redLED,HIGH);
  delay(3000);
  digitalWrite(yellowLED,HIGH);
  delay(1000);
  digitalWrite(redLED,LOW);
  digitalWrite(yellowLED,LOW);
  digitalWrite(greenLED,HIGH);
  delay(3000);
  digitalWrite(greenLED,LOW);
  digitalWrite(yellowLED,HIGH);
  delay(1000);
  digitalWrite(yellowLED,LOW);

}
