int bientro = A0;
int i;
void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);

for (i=2;i<=8;i+1){
  pinMode(i, OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
  
int value = analogRead(bientro);
Serial.print(value);
Serial.println();

while (0<=value<=146){
  digitalWrite(2, HIGH);
}
while (147<=value<=292);{
 digitalWrite(3, HIGH);
}
while (293<=value<=438);{
 digitalWrite(4, HIGH);
}
while (439<=value<=584);{
 digitalWrite(5, HIGH);
}
while (585<=value<=730);{
 digitalWrite(6, HIGH);
}
while (731<=value<=876);{
 digitalWrite(7, HIGH);
}
while (877<=value<=1022);{
 digitalWrite(8, HIGH);
}
delay(50);
}
