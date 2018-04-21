#include <Servo.h>

float x,y,z;
int a,b;
int pos;
int motorleft = 6;
int motorright = 9;
void setup()
{
Serial.begin(9600);

pinMode(motorleft, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);

pinMode(motorright, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
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
pos = map(int(y), -8, 8, -200, 200);
int val = map(int(x), -9, 9, -255, 255);

if (val<0){
analogWrite(motorleft, (-val)+pos);
digitalWrite(2, LOW);
digitalWrite(3, HIGH);

analogWrite(motorright, (-val)+pos);
digitalWrite(7, HIGH);
digitalWrite(8, LOW);
}
else{
analogWrite(motorleft, val-pos);
digitalWrite(2, HIGH);
digitalWrite(3, LOW);

analogWrite(motorright, val-pos);
digitalWrite(7, LOW);
digitalWrite(8, HIGH);
}
delay(5);
}
}
}
