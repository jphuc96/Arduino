int i;
int a;
int time = 50;
void setup() {
  // put your setup code here, to run once:
  for(i=2;i<=8;i=i+1)
  {
    pinMode(i, OUTPUT);
  }
}
void loop() {
  // put your main code here, to run repeatedly:

for (a=2;a<=8;a=a+1)
{
  for(i=2;i<=10-a;i=i+1)
  {
    digitalWrite(i, HIGH);
    delay(time);
    digitalWrite(i, LOW);
    delay(time);
  }
digitalWrite(10-a, HIGH);
}
  for(i=2;i<=8;i=i+1)
  {digitalWrite(i, LOW);}
}
