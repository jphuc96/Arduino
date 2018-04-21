int i;
void setup() {
  // put your setup code here, to run once:
for (i=2;i<=8;i+1)
pinMode(i, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

for (i = 2;i<=8;i=i+1)
{
digitalWrite(i, HIGH);
delay(50);
digitalWrite(i, LOW);
delay(50);
}
for (i = 7;i>=3;i=i-1)
{
digitalWrite(i, HIGH);
delay(50);
digitalWrite(i, LOW);
delay(50);
}
}
