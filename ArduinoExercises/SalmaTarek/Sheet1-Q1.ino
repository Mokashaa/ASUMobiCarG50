#define LED 7

void setup() {  
  pinMode(LED, OUTPUT);
}

void loop() {
digitalWrite(LED, HIGH);
delay(2000); //ON Time
digitalWrite(LED, LOW);
delay(6000); //OFF Time
}
