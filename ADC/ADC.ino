#include <SevenSeg.h>
SevenSeg disp1(6,7,8,9,10,11,12);
SevenSeg disp2(6,7,8,9,10,11,12);

const int numOfDigits1 = 3;
const int numOfDigits2 = 3;

int digitPins1[numOfDigits1]={0,1,2};
int digitPins2[numOfDigits2]={3,4,5};

double value1,voltage1,value2,voltage2;


void setup() {
  // put your setup code here, to run once:
  disp1.setDigitPins(numOfDigits1,digitPins1);
  disp1.setDPPin(13);
  disp1.setDigitDelay(1667);
  disp2.setDigitPins(numOfDigits2,digitPins2);
  disp2.setDigitDelay(1667);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  value1 = map(analogRead(A1),0,802,1,1196);
  voltage1 = value1/100;
  value2 = map(analogRead(A2),0,802,1,1196);
  voltage2 = value2/100;

  disp1.write(value1/100);
  disp1.clearDisp();
  disp2.write(10.3);
  disp2.clearDisp();
  
}
