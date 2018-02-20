
#define LED01 13 
#define LED02 12
#define LED03 11
#define LED04 10

void setup()
{
pinMode(LED01, OUTPUT);
pinMode(LED02, OUTPUT); 
pinMode(LED03, OUTPUT); 
pinMode(LED04, OUTPUT); 
}

void loop()
{
digitalWrite(LED01, HIGH); 
delay(30);
digitalWrite(LED02, HIGH); 
delay(30);
digitalWrite(LED01, LOW); 
delay(30);
digitalWrite(LED03, HIGH); 
delay(30);
digitalWrite(LED02, LOW);
delay(30);
digitalWrite(LED04, HIGH); 
delay(30);
digitalWrite(LED03, LOW);
delay(30);
digitalWrite(LED04, LOW);
delay(30);
digitalWrite(LED04, HIGH);
delay(30);
digitalWrite(LED03, HIGH);
delay(30);
digitalWrite(LED04, LOW);
delay(30);
digitalWrite(LED02, HIGH);
delay(30);
digitalWrite(LED03, LOW);
delay(30);
digitalWrite(LED01, HIGH);
delay(30);
digitalWrite(LED02, LOW);
delay(30);
digitalWrite(LED01, HIGH);
}


