#include <Servo.h>

#define TRIG_PIN 4
#define ECHO_PIN 5
#define TIME_OUT 20000

 float GetDistance()
{
  long duration, distanceCm;
   
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH, TIME_OUT);
 
  // convert to distance
  distanceCm = duration / 29.1 / 2;
  
  return distanceCm;
}

float x,y,z;
int a,b;
int pos;
int motorleft = 6;
int motorright = 9;
void setup()
{
Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);

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
pos = map(int(y), -9, 9, -255, 255);
int val = map(int(x), -9, 9, -255, 255);

if( pos < -3 ){ 
  analogWrite(9, 150);
  digitalWrite(7, HIGH);
  digitalWrite(8 , LOW);
}
if( pos > 3 ){
  analogWrite(9, 150);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}



if (val>=0){
analogWrite(motorleft, val);
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
Serial.print("tien: ");
Serial.print(val);
Serial.println();
}

if(val<0){

analogWrite(motorleft, -val);
digitalWrite(3, HIGH);
digitalWrite(2, LOW);  
Serial.print("lui: ");
Serial.print(-val);
Serial.println();
}
}
delay(5);
}

long distance = GetDistance();

if (distance <15){
analogWrite(motorleft, 255);
digitalWrite(3, HIGH);
digitalWrite(2, LOW);  
delay(1000);
analogWrite(motorleft, 0);
}
}
