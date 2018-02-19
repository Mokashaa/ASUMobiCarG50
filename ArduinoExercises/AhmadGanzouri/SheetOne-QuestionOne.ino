  int LED = 13; // using the internal  LED of the arduino at pin 13 or external led..
  int ONTime = 2000; // 2 seconds delay
  int OFFTime = 6000; // 6 seconds delay 
  
void setup() {


pinMode(LED,OUTPUT); // type of the pin is output
  
}

void loop() {

  digitalWrite(LED,HIGH); 
  delay(ONTime);

  digitalWrite(LED,LOW);
  delay(OFFTime);
  
}
