int LED [] = {4,5,6,7}; //Array of LEDS, LED[0] at Pin 4, LED[1] at pin 5, LED[2] at pin 6, LED[3] at pin 7.
int x = 0;

void setup() {
  for (x = 0; x < 4; x++)
  {
    pinMode(LED[x],OUTPUT); //identifying each LED as an OUTPUT Pin
  }
}

void loop() {
  for(x = 0; x < 4; x++)
  {
    digitalWrite(LED[x],HIGH); //bouncing from Left to Right : 4,5,6,7
    delay(1000); //1 second between each bounce
    digitalWrite(LED[x],LOW); //Turns The LED OFF
  }
  for(x = 2; x >= 0; x--)
  {
    digitalWrite(LED[x],HIGH); //bouncing from right to left 6,5,4
    delay(1000); //1 second delay between each bounce
    digitalWrite(LED[x],LOW); //Turns The LED OFF
  }
}
