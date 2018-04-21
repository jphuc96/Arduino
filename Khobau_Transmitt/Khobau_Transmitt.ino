
#include <SPI.h>   
#include "RF24.h"  
#include <Servo.h>  

Servo myservo;          


//None yet

RF24 myRadio (2, 3); // [CE,CS]

byte addresses[][6] = {"1Node"};

int data[5];
int dir,spd,led_out,led_in,lock;

void setup() 
{
  for(int i=4;i<=10;i++)
  pinMode(i,OUTPUT);
  
  Serial.begin(9600);
  delay(1000);
  Serial.println(F("Kho bau camping - Trans"));

  myRadio.begin();  
  myRadio.setChannel(108);  
  myRadio.setDataRate(RF24_250KBPS);
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.openWritingPipe( addresses[0]); 
  delay(1000);
}

void manual_unlock(){
  delay(3000);
  pinMode(3,OUTPUT);
  int servoPin = 3;  
  myservo.attach(servoPin); 
  if(lock==0){
  myservo.write(135); //lock
  }
  else
  myservo.write(6); //unlock
}
void loop() 
{
  // open/close
  int button_1 = digitalRead(4);
  int button_2 = digitalRead(5);
  if(button_1==1&&button_2==0)
    dir = 1;
  else if(button_1==0&&button_2==1)
    dir = 2;
  else 
    dir = 0;

  // unlock
  lock = digitalRead(7);
  if(lock == 0)
  dir = 0;

  //led control
  led_in = digitalRead(8);
  led_out = digitalRead(9);
  
  // manual unlock
  if(digitalRead(6)==1)
  manual_unlock();
  
spd = 700;
data[0] = dir;
data[1] = spd;
data[2] = led_out;
data[3]= led_in;
data[4] = lock;

myRadio.write( &data, sizeof(data) );

}
