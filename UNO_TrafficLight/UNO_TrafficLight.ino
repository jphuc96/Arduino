#include <TimerOne.h>
#define Light    PORTC
#define SegData  PORTD
#define SegCom   PORTB

int State[4] = {0x21,0x11,0x0C,0x0A};
int SegCode[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int SegState[4]={0x01,0x02,0x04,0x08};
int count = 0;
int d1=0,d2=0,d3=0,d4=0;

void Num1(int num){
  d1 = num/10;
  d2 = num%10;
}
void Num2(int num){
  d3 = num/10;
  d4 = num%10;  
}
void LightState(int state){
  Light = State[state];
}
void timerIsr()
{
  Timer1.detachInterrupt();  //stop the timer
   switch(count++){
    case 0:
      SegData = SegCode[d1];
      SegCom = SegState[0];
      break;
    case 1:
      SegData = SegCode[d2];
      SegCom = SegState[1];
      break;
    case 2:
      SegData = SegCode[d3];
      SegCom = SegState[2];
      break;
    case 3:
      SegData = SegCode[d4];
      SegCom = SegState[3];
      count = 0;
      break;
   }
  Timer1.attachInterrupt( timerIsr );  //enable the timer
}


void setup() {
DDRC = 0x3F;  //LED Port
DDRD = 0xFF;  //Data Port
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);

Timer1.initialize(1000); // set timer for 1ms
Timer1.attachInterrupt( timerIsr ); // enable the timer
}
int TimeInterval = 1000;

void loop() { 
int TimeR1 = 10;
int TimeY1 = 3;
int TimeG1 = 15;
int TimeR2 = TimeG1+TimeY1+1;
int TimeY2 = TimeY1;
int TimeG2 = TimeR1-TimeY1-1;

while(TimeG2!=-1){
  Num1(TimeR1--);
  Num2(TimeG2--);
  LightState(0);  
  delay(TimeInterval);
}

while(TimeY2!=-1){
  Num1(TimeR1--);
  Num2(TimeY2--);
  LightState(1);  
  delay(TimeInterval);
}

while(TimeG1!=-1){
  Num1(TimeG1--);
  Num2(TimeR2--);
  LightState(2);  
  delay(TimeInterval);
}

while(TimeY1!=-1){
  Num1(TimeY1--);
  Num2(TimeR2--);
  LightState(2);  
  delay(TimeInterval);
}

}
