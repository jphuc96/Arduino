
#include <SPI.h>   
#include "RF24.h"  

//None yet

RF24 myRadio (9, 10);

byte addresses[][6] = {"1Node"};

int joystick[2];


float x,y,z;
int a,b;

void setup() 
{
  
  Serial.begin(9600);
  delay(1000);
  Serial.println(F("RF24/Simple Transmit data Test"));
 
  myRadio.begin(); 
  myRadio.setChannel(108);  
  myRadio.setDataRate(RF24_250KBPS);
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.openWritingPipe( addresses[0]); 
  delay(1000);
}


void loop() 
{

  Serial.flush();
if (Serial.available() > 0) {
a = Serial.parseInt();
b = Serial.parseInt();
x = Serial.parseFloat();
y = Serial.parseFloat();
z = Serial.parseFloat();

Serial.print("X: ");
Serial.print(x);
Serial.print("            ");
Serial.print("Y: ");
Serial.print(y);
Serial.println();


  joystick[0] = x*100;
  joystick[1] = y*100;

  myRadio.write( &joystick, sizeof(joystick) );
}
  
}
