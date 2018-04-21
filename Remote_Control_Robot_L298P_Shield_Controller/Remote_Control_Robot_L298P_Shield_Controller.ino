
#include <SPI.h>   
#include "RF24.h"  

//None yet

RF24 myRadio (4, 5); // [CE,CS]

byte addresses[][6] = {"1Node"};

int joystick[4];
int X,XX,Y,SW;

 int count=2;
 int temp=0;
void setup() 
{  
  Serial.begin(9600);
  delay(1000);
  Serial.println("Spying Robot!!!");

  myRadio.begin(); 
  myRadio.setChannel(108);  
  myRadio.setDataRate(RF24_250KBPS);
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.openWritingPipe( addresses[0]); 

  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(0,switch_led,FALLING);
}

void switch_led(){
  count++;
  if(count%2==1){
  SW=1;
  }
  else{
  SW=0;
  }
}
void loop() 
{
  Y = map(analogRead(A2),0,1023,-255,255);
  X = map(analogRead(A1),0,1023,-255,255);

  //Map X into Y scale:
  XX = map(X,-255,255,-Y,Y);

  joystick[0] = Y;
  joystick[1] = XX;
  joystick[2] = X;
  joystick[3] = SW;

  
  Serial.print("Y = ");
  Serial.print(joystick[0]);  
  Serial.print("   XX = ");
  Serial.print(joystick[1]);
  Serial.print("   X = ");
  Serial.print(joystick[2]);   
  Serial.print("   SW = ");
  Serial.println(joystick[3]); 
  
 myRadio.write( &joystick, sizeof(joystick) );
  
}
