
int x;
int i;
int lspeed=0,rspeed=0;
int right=3, left=6;
int in1=4,in2=5;

void setup() {
  // put your setup code here, to run once:
  for(i=3;i<=6;i++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(in1,0);
  digitalWrite(in2,0);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(left,lspeed);
  analogWrite(right,rspeed);

if(Serial.available()>0){
Serial.flush();
x = Serial.parseInt();
Serial.println(x);
switch(x){
  case 1:
  lspeed = 60;
  rspeed = 60;
  break;
  case 2:
  rspeed = 60;
  lspeed = 30;
  break;
  case 3:
  lspeed = 60;
  rspeed = 30;
  break;
  case 4:
  lspeed = rspeed = 0;
  break;
}
}

}
