#include <SevenSeg.h>

SevenSeg disp(6,7,8,9,10,11,12);

 const int numOfDigits =3;
 int digitPins[numOfDigits]={3,4,5};

 void setup () {
Serial.begin(9600);
 disp.setDigitPins( numOfDigits , digitPins );
 disp.setDPPin(13);
 }

 void loop () {
  float value = map(analogRead(A0),0,1023,100,150);
  disp.write(value/10);
 



 }
