
#include <SPI.h>  
#include "RF24.h"  


RF24 myRadio (2, 3); // [CE,CS]
byte addresses[][6] = {"1Node"};
int joystick[5];

unsigned long nodatatime;
unsigned long waittime = 5000;
void setup()  
{
 
  pinMode(12, OUTPUT);
  Serial.begin(115200);
  delay(1000);
  Serial.println(F("RF24/Simple Receive data Test"));



  myRadio.begin(); 
  myRadio.setChannel(108);
  myRadio.setDataRate(RF24_250KBPS);
  myRadio.setPALevel(RF24_PA_MIN);  
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();

}


void loop() 
{

  if ( myRadio.available())
  {

    while (myRadio.available())  
    {
      myRadio.read( &joystick, sizeof(joystick) ); 
 
    }
   

  Serial.print(F("X = "));
  Serial.print(joystick[0]);  
  Serial.print(F("   Y = "));
  Serial.print(joystick[1]);
  Serial.print(F("   A = "));
  Serial.print(joystick[2]);  
  Serial.print(F("   B = "));
  Serial.print(joystick[3]);
    //LED Control:
  Serial.print(F("   LED: "));
  
  if(joystick[4]==0){
  Serial.print("ON");
  digitalWrite(4, HIGH);
  }
  else{
   digitalWrite(4, LOW);
  Serial.print("OFF");
  }
  Serial.println();
  //End LED Control
  
    analogWrite(9, map(joystick[0],0,1023,120,254));
    analogWrite(5, map(joystick[1],0,1023,120,254));
    analogWrite(45, map(joystick[2],0,1023,120,254));
    analogWrite(10, map(joystick[3],0,1023,120,254));
    
  }
else{
   nodatatime = millis();
   while(myRadio.available()== false){
    if(millis() - nodatatime > waittime){
      Serial.println("Warning, landing");      
      }
    }
  
  }
  

}
