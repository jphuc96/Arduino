#include <SPI.h>  
#include "RF24.h"  


RF24 myRadio (22, 23); // [CE,CS]
byte addresses[][6] = {"1Node"};

int joystick[3];
int Y;
int X,X_raw;

unsigned long nodatatime;
unsigned long waittime = 3000;

int enA=10 ,dirA=12; 
int enB=11 ,dirB=13;
int i;

//Function prototype:
void motorGo(int y,int x,int x_raw);
void RF24_Init();


void setup() {
  pinMode(enA,OUTPUT);
  pinMode(dirA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(dirB,OUTPUT);
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

  Serial.print("X = ");
  Serial.print(X);  
  Serial.print("   Y = ");
  Serial.print(Y);
  Serial.print("       X_raw = ");  
  Serial.print(X_raw);
  Serial.print("       "); 
  motorGo(Y,X,X_raw); 
 Serial.println();
  }
else{
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
