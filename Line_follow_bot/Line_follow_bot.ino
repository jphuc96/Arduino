int motorleft=6;
int in1=4;
int in2=5;
int motorright=3;
int in3=7;
int in4=8;
int left=9;
int right=10;
int modeleft, moderight;
int lspeed,rspeed;
void setup() {
  // put your setup code here, to run once:
pinMode(motorleft,OUTPUT);
pinMode(motorright,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(11,OUTPUT);
digitalWrite(11,1);
pinMode(left,INPUT);
pinMode(right,INPUT);

  lspeed=100;
  rspeed=0.90*lspeed;
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(in1,1);
digitalWrite(in2,0);
digitalWrite(in3,0);
digitalWrite(in4,1);
modeleft = digitalRead(left);
moderight = digitalRead(right);

if(moderight==1||modeleft==1){
  analogWrite(motorright,rspeed-moderight*0.5*rspeed);
  analogWrite(motorleft,lspeed-modeleft*0.5*lspeed);
}
else{
  analogWrite(motorright,rspeed);
  analogWrite(motorleft,lspeed);
}

}
