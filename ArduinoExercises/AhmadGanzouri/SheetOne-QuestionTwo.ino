int LED1 = 4;
int LED2 = 5;
int LED3 = 6;
int LED4 = 7;

void setup() {
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);  //All pins are output 
pinMode(LED3,OUTPUT);
pinMode(LED4,OUTPUT);

}

void loop() {
  digitalWrite(LED1,HIGH);    // LED1 ON
  delay(1000);
  
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);        // LED2 ON
  delay(1000);

  digitalWrite(LED2,LOW);
  digitalWrite(LED3,HIGH);    //LED3 ON
  delay(1000);

  digitalWrite(LED3,LOW);
  digitalWrite(LED4,HIGH);   //LED4 ON
  delay(1000);

  digitalWrite(LED4,LOW);
  digitalWrite(LED3,HIGH);  // LED3 ON
  delay(1000);

  digitalWrite(LED3,LOW);
  digitalWrite(LED2,HIGH);       // LED2 ON
  delay(1000);
  
  digitalWrite(LED2,LOW);
}
