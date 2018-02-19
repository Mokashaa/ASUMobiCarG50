int LED1 = 4;
int LED2 = 5;
int LED3 = 6;
int LED4 = 7;
int ONTime = 1000;  // delay time 1 second.

void setup() {
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);  //All pins are output 
pinMode(LED3,OUTPUT);
pinMode(LED3,OUTPUT);

}

void loop() {
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);         // LED1 ON
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  delay(ONTime);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED1,LOW);         // LED2 ON
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  delay(ONTime);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);        //LED3 ON
  digitalWrite(LED4,LOW);
  delay(ONTime);
  digitalWrite(LED4,HIGH);
  digitalWrite(LED2,LOW);        // LED4 ON
  digitalWrite(LED3,LOW);
  digitalWrite(LED1,LOW);
  delay(ONTime);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED2,LOW);
  digitalWrite(LED1,LOW);        //LED3 ON
  digitalWrite(LED4,LOW);
  delay(ONTime);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED1,LOW);       // LED2 ON
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  delay(ONTime);
}
