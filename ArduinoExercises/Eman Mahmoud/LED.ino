
int LED=13;
  int onTime=500;
  int offTime=500;
void setup() {
  pinMode(LED,OUTPUT);
  
 }

void loop() {
  digitalWrite (LED,HIGH);
  delay(onTime);
  digitalWrite(LED,LOW);
  delay(offTime);
}
