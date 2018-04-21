int right=3,bb=4,aa=5,left=6;
int ss1=9,ss2=10,ss3=11,ss4=12,ss5=2;
int s1,s2,s3,s4,s5;
int lspeed,rspeed,sspeed = 100;
void setup() {
  // put your setup code here, to run once:
pinMode(left,OUTPUT);
pinMode(bb,OUTPUT);
pinMode(aa,OUTPUT);
pinMode(right,OUTPUT);
pinMode(ss1,INPUT);
pinMode(ss2,INPUT);
pinMode(ss3,INPUT);
pinMode(ss4,INPUT);
pinMode(ss5,INPUT);

digitalWrite(bb,0);
digitalWrite(aa,0);

Serial.begin(9600);

lspeed = rspeed = sspeed;

analogWrite(right,sspeed);
analogWrite(left,sspeed);
}

void loop() {
  // put your main code here, to run repeatedly:
s1 = digitalRead(ss1);
s2 = digitalRead(ss2);
s3 = digitalRead(ss3);
s4 = digitalRead(ss4);
s5 = digitalRead(ss5);


Serial.print(s5);
Serial.print("          ");
Serial.print(s4);
Serial.print("          ");
Serial.print(s3);
Serial.print("          ");
Serial.print(s2);
Serial.print("          ");
Serial.print(s1);
Serial.print("          ");
Serial.println();

while(s1==0||s2==0){
  if(s2==0){
analogWrite(left,sspeed);
analogWrite(right,sspeed/2);

Serial.print(sspeed/2);
Serial.print("          ");
Serial.println();
  }
  if(s1==0){
analogWrite(left,sspeed);
analogWrite(right,sspeed/4);

Serial.print(sspeed/4);
Serial.print("          ");
Serial.println();
  }
  else{
  analogWrite(right,sspeed);
  analogWrite(left,sspeed);
}
}

while(s4==0||s5==0){  
  if(s4==0){
analogWrite(right,sspeed);
analogWrite(left,sspeed/2);

Serial.print(sspeed/2);
Serial.print("          ");
Serial.println();
  }
  if(s5==0){
analogWrite(right,sspeed);
analogWrite(left,sspeed/4);

Serial.print(sspeed/4);
Serial.print("          ");
Serial.println();
  }
  else{
  analogWrite(right,sspeed);
  analogWrite(left,sspeed);
}
}


}
