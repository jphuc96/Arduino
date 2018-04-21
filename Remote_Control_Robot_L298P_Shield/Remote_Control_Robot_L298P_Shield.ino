#include <SPI.h>  
#include "RF24.h"  

#define TRIG_PIN A0
#define ECHO_PIN A1
#define TIME_OUT 20000
#define LED_PIN 7
RF24 myRadio (4, 5); // [CE,CS]
byte addresses[][6] = {"1Node"};

int joystick[4];
int Y;
int X,X_raw;
int SW;

unsigned long nodatatime;
unsigned long waittime = 3000;

int enA=10 ,dirA=8; 
int enB=9 ,dirB=6;

int i;

//Function prototype:
void motorGo(int y,int x,int x_raw);
void RF24_Init();


void setup() {
  pinMode(enA,OUTPUT);
  pinMode(dirA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(dirB,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("===================Spying Robot===================");
  Serial.println("By E-TECH CLUB of School of Electrical Engineering");
  RF24_Init();

}

void RF24_Init(){
    myRadio.begin(); 
  myRadio.setChannel(108);
  myRadio.setDataRate(RF24_250KBPS);
  myRadio.setPALevel(RF24_PA_MAX);  
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();
}
/* ===========ORIENTATION==============
 *  y = -255:255
 *  x = -255:555
    MOTOR B                 MOTOR A
                   Y+       
                   |
                   |
          X-_ _ _ _|_ _ _ _X+
                   |
                   |
                   |
                   Y-
 */
 
void motorGo(int y,int x,int x_raw)
{   if(y>60){
    digitalWrite(dirA,HIGH);
    digitalWrite(dirB,HIGH);
    if(x>=0){
    analogWrite(enA,y-x);
    analogWrite(enB,y);
    }
    else{
    analogWrite(enA,y);
    analogWrite(enB,y+x);
    }
    
}
    if(y<-60){
    digitalWrite(dirA,LOW);
    digitalWrite(dirB,LOW);
    if(x>=0){
    analogWrite(enA,-y);
    analogWrite(enB,-y-x);
    }  
    else{
    analogWrite(enA,-y+x);
    analogWrite(enB,-y); 
    }
}
if(y>=-60&&y<=60){
    if(x_raw>=0){
    digitalWrite(dirA,LOW);
    digitalWrite(dirB,HIGH);
    analogWrite(enA,x_raw);
    analogWrite(enB,x_raw);   
}
    else{
    digitalWrite(dirA,HIGH);
    digitalWrite(dirB,LOW);
    analogWrite(enA,-x_raw);
    analogWrite(enB,-x_raw);
    }
}
}

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

void loop() 
{
if ( myRadio.available())
  {
    while (myRadio.available())  
    {
      myRadio.read( &joystick, sizeof(joystick) );  
    }
   
Y = joystick[0];
X = joystick[1];
X_raw = joystick[2];
SW = joystick[3];
  Serial.print("X = ");
  Serial.print(X);  
  Serial.print("   Y = ");
  Serial.print(Y);
  Serial.print("       X_raw = ");  
  Serial.print(X_raw);
  Serial.print("       SW = "); 
  Serial.println(SW);
 // Serial.print("       DistanceCm = "); 
 // Serial.println(GetDistance());

//  if(GetDistance()<=7&&GetDistance()>=3)
//  motorGo(0,0,0);
//  else
  motorGo(Y,X,X_raw); 
  
  digitalWrite(LED_PIN,SW);
  }
else{
 //     if(GetDistance()<=7&&GetDistance()>=3)
 //     motorGo(0,0,0);
 //     else
      Serial.println("No signal! Stop in 3s: ");
      nodatatime = millis();
      while(myRadio.available()==false){
      if(millis() - nodatatime > waittime){
      motorGo(0,0,0);
      nodatatime=0;
      }
      }
  }
}
