int LED [] = {4,5,6,7};
int x = 0;

void setup() {
  for (x = 0; x < 4; x++)
  {
    pinMode(LED[x],OUTPUT);
  }
}

void loop() {
  for(x = 0; x < 4; x++)
  {
    digitalWrite(LED[x],HIGH);
    delay(1000);
  }
  for(x = 3; x >= 0; x--)
  {
    digitalWrite(LED[x],HIGH);
    delay(1000);
  }
}
