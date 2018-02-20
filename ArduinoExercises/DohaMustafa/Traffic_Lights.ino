int redledPin =4;
int yellowledPin=5;
int greenledPin=6;
int x=0;

void setup() {
  pinMode(redledPin,OUTPUT);
  pinMode(yellowledPin,OUTPUT);
  pinMode(greenledPin,OUTPUT);
  
}

void loop() {
  digitalWrite(greenledPin,HIGH); //the green light is on for 8 secs and then goes off
  delay(8000);
  digitalWrite(greenledPin,LOW);
  
  for(x=0;x<10;x++) //yellow light blinks 10 times and then goes off
  {
    digitalWrite(yellowledPin,HIGH);
    delay(2000);
    digitalWrite(yellowledPin,LOW);
  }
  
  digitalWrite(redledPin,HIGH); //red light is on for 8 secs and then goes off
  delay(8000);
  digitalWrite(redledPin,LOW);
}
