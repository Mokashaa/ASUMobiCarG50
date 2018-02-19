  int LED = 13; // using the internal LED of the arduino at pin 13 
  int ONTime = 2000; // 2 seconds delay
  int OFFTime = 6000; // 6 seconds delay 
  
void setup() {
Serial.begin(9600);

pinMode(LED,OUTPUT); // type of the pin is output
  
}

void loop() {

  digitalWrite(LED,HIGH); 
  delay(ONTime);
  Serial.println("ON"); // to make sure of the time 
  digitalWrite(LED,LOW);
  delay(OFFTime);
  Serial.println("OFF"); // same as the previous 
}
