
#include <SPI.h>   
#include "RF24.h"  

//None yet

RF24 myRadio (2, 3); // [CE,CS]

byte addresses[][6] = {"1Node"};

int joystick[5];


void setup() 
{
  
  Serial.begin(115200);
  delay(1000);
  Serial.println(F("RF24/Simple Transmit data Test"));
  pinMode(2, INPUT);

  myRadio.begin(); 
  myRadio.setChannel(108);  
  myRadio.setDataRate(RF24_250KBPS);
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.openWritingPipe( addresses[0]); 
  delay(1000);
}


void loop() 
{
  joystick[0] = analogRead(A0);
  joystick[1] = analogRead(A1);
  joystick[2] = analogRead(A2);
  joystick[3] = analogRead(A3);
  joystick[4] = analogRead(A4);
  myRadio.write( &joystick, sizeof(joystick) );

  
  Serial.print(F("X = "));
  Serial.print(joystick[0]);  
  Serial.print(F("   Y = "));
  Serial.print(joystick[1]);
  Serial.print(F("   A = "));
  Serial.print(joystick[2]);  
  Serial.print(F("   B = "));
  Serial.print(joystick[3]);
  Serial.print(F("   LED: "));
  if(joystick[4]==0)
  Serial.print("OFF");
  else
  Serial.print("ON");
  Serial.println();
  
}
