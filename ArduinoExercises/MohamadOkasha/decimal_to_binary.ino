#define AINPUT 0
#define OP 2
void setup()
{
  for(int i=0;i<10;i++)
  pinMode(OP+i, OUTPUT);
  analogReference(EXTERNAL);
  }
int value = 0;
void loop()
{
  value = analogRead(AINPUT);
  for(int i=0;i<10;i++){
    digitalWrite(OP+i, value&0x1);
    value>>=1;
    }
    }
