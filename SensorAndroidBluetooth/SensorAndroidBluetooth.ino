
float x,y,z;
int a,b;
int pos;
int motorleft = 9;
int motorright = 10;
void setup()
{
Serial.begin(9600);

pinMode(motorleft, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);

pinMode(motorright, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
}
void loop()

{
Serial.flush();

if (Serial.available() > 0) {
a = Serial.parseInt();
b = Serial.parseInt();
y = Serial.parseFloat();
x = Serial.parseFloat();
z = Serial.parseFloat();

if(-11<x,y,z<11){
pos = map(int(y), -9, 9, -255, 255);
int val = map(int(x), -9, 9, -255, 255);


Serial.print("pos: ");
Serial.print(pos);
Serial.print("       ");
Serial.print("val: ");
Serial.print(val);
Serial.print("       ");
Serial.println();


if (val<0&&val>=-255){
analogWrite(motorleft, -val);
digitalWrite(8, LOW);


analogWrite(motorright, -val);
digitalWrite(6, LOW);


if(pos<0){
  analogWrite(motorleft, -val+map(pos,0,-255,0,val));
}
else{
  analogWrite(motorright, -val-map(pos,0,-255,0,val));
}
}
if (val>0&&val<255){
analogWrite(motorleft, val);
digitalWrite(8,HIGH);


analogWrite(motorright, val);
digitalWrite(6, HIGH);

if(pos>0){
  analogWrite(motorleft, val+map(pos,0,-255,0,val));
}
else{
  analogWrite(motorright, val-map(pos,0,-255,0,val));
}
}

}

}

else{
analogWrite(motorleft,0);
digitalWrite(8, LOW);


analogWrite(motorright,0);
digitalWrite(6, LOW);
}
}
