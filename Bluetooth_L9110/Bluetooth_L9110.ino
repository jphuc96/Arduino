
float x,y,z;
int a,b;
int pos;
int motorleft = 6;
int motorright = 3;
void setup()
{
Serial.begin(9600);
pinMode(motorleft, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(motorright, OUTPUT);
}
void loop()

{
int speed;
Serial.flush();
if (Serial.available() > 0) {
a = Serial.parseInt();
b = Serial.parseInt();
x = Serial.parseFloat();
y = Serial.parseFloat();
z = Serial.parseFloat();

if(-11<x,y,z<11){
pos = map(int(y), -9, 9, -255, 255);
int val = map(int(x), -9, 9, -100, 100);

if (val<0){
analogWrite(motorleft, (255+val));
digitalWrite(4, HIGH);
analogWrite(motorright, (255+val));
digitalWrite(5, HIGH);
if(pos<0){
  analogWrite(motorleft, (255+val)+pos);
}
else{
  analogWrite(motorright, (255+val)-pos);
}
}
else{
analogWrite(motorleft, val);
digitalWrite(4, LOW);
analogWrite(motorright, val);
digitalWrite(5, LOW);
if(pos>0){
  analogWrite(motorleft, val+pos);
}
else{
  analogWrite(motorright, val-pos);
}
}
}
}
}
