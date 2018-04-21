int i;
int button1, button2;
int mode1=0, mode2=0;
void setup() {
  // put your setup code here, to run once:
for(i=2;i<=9;i++){
  pinMode(i,OUTPUT);
}
pinMode(10,INPUT);
pinMode(11,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
delay(100);
button1=digitalRead(10);
button2=digitalRead(11);


if((button1 == 1)&&(button2 == 0)){
  for(i=2;i<=9;i++){
  digitalWrite(i,HIGH);
  delay(100);
}
for(i=2;i<=9;i++){
  digitalWrite(i,LOW);
  delay(100);
}
}

if((button1 == 0)&&(button2 == 1)){
  for(i=2;i<=9;i++){
  digitalWrite(i,HIGH);
  delay(100);
}
for(i=9;i>=2;i--){
  digitalWrite(i,LOW);
  delay(100);
}
}

if((button1 == 1)&&(button2 == 1)){
  for(i=2;i<=8;i++){
  digitalWrite(i,HIGH);
  delay(100);
  digitalWrite(i,LOW);
  delay(100);
}
for(i=9;i>=3;i--){
  digitalWrite(i,HIGH);
  delay(100);
  digitalWrite(i,LOW);
  delay(100);
}
}

for(i=2;i<=9;i++){
  digitalWrite(i,LOW);
}

}
