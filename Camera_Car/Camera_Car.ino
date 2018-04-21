
#include <SPI.h>  
#include "RF24.h"  


RF24 myRadio (9, 10);
byte addresses[][6] = {"1Node"};
int joystick[2];

unsigned long nodatatime;
unsigned long waittime = 5000;



float x,y,z;
int a,b;
int pos;
int motorleft = 6;
int motorright = 3;



void setup()  
{
 
  pinMode(12, OUTPUT);
 Serial.begin(9600);
  delay(1000);
  Serial.println(F("RF24/Simple Receive data Test"));



  myRadio.begin(); 
  myRadio.setChannel(108);
  myRadio.setDataRate(RF24_250KBPS);
  myRadio.setPALevel(RF24_PA_MIN);  
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();


pinMode(motorleft, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);

pinMode(motorright, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);


}


void loop() 
{

  if ( myRadio.available())
  {

    while (myRadio.available())  
    {
      myRadio.read( &joystick, sizeof(joystick) ); 
 
    }
   
x = joystick[0];
y = joystick[1];

if(-11<x,y,z<11){
pos = map(int(y), -9, 9, -255, 255);
int val = map(int(x), -9, 9, -255, 255);

if (val<0){
analogWrite(motorleft, -val);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);

analogWrite(motorright, -val);
digitalWrite(7, HIGH);
digitalWrite(8, LOW);

if(pos<0){
  analogWrite(motorleft, -val+pos);
}
else{
  analogWrite(motorright, -val-pos);
}
}
else{
analogWrite(motorleft, val);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);

analogWrite(motorright, val);
digitalWrite(7, LOW);
digitalWrite(8, HIGH);
if(pos>0){
  analogWrite(motorleft, val+pos);
}
else{
  analogWrite(motorright, val-pos);
}
}

}
delay(4);
}
}
  
