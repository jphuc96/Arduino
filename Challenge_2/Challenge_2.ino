int i;
int button1;
int button2;
int pot;
int light;
int temp1,temp2;
int count1=0, count2=0, count3=0;
void setup() {
  // put your setup code here, to run once:
for(i=2;i<=10;i++){
  pinMode(i,OUTPUT);
Serial.begin(9600);
}
pinMode(button1,INPUT);
pinMode(button2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
pot = analogRead(A0);
light = analogRead(A1);
button1 = digitalRead(11);
button2 = digitalRead(12);

if(button1==1&&button2==0){
temp1 = map(pot,0,1023,1,9);

  for(i=2;i<=temp1;i++)
    digitalWrite(i,HIGH);
  for(i=9;i>temp1;i--)
    digitalWrite(i,LOW);
    
    if(temp1==9)
    digitalWrite(10,HIGH);
    else
    digitalWrite(10,LOW);
}

if(button1==0&&button2==1){
  temp2 = map(light,0,1023,1,9);
Serial.println(temp2);
    for(i=9;i>=9-temp2;i--)
    digitalWrite(i,HIGH);
    for(i=2;i<(9-temp2);i++)
    digitalWrite(i,LOW);

    if(temp2==8)
    digitalWrite(10,HIGH);
    else
    digitalWrite(10,LOW);
}

if(button1==1&&button2==1){
  temp1 = map(pot,0,1023,1,9);
  temp2 = map(light,0,1023,1,9);

    for(i=2;i<=temp1;i++)
    digitalWrite(i,HIGH);
 
    for(i=9;i>temp1;i--)
    digitalWrite(i,LOW);

    for(i=9;i>=(9-temp2);i--)
    digitalWrite(i,HIGH);
 
    for(i=2;i<(9-temp2);i++)
    digitalWrite(i,LOW);

    if(temp1==9-temp2)
    digitalWrite(10,HIGH);
    else
    digitalWrite(10,LOW);
    
}


}
