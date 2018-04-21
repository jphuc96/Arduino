#include <SevenSeg.h>
SevenSeg disp1(6,7,8,9,10,11,12);
SevenSeg disp2(6,7,8,9,10,11,12);

const int numOfDigits1 = 3;
const int numOfDigits2 = 3;

int digitPins1[numOfDigits1]={0,1,2};
int digitPins2[numOfDigits2]={3,4,5};

void setup() {
  // put your setup code here, to run once:
  disp1.setDigitPins(numOfDigits1,digitPins1);
  disp1.setDigitDelay(1667);
  disp2.setDigitPins(numOfDigits2,digitPins2);
  disp2.setDigitDelay(1667);
}

void loop() {
  // put your main code here, to run repeatedly:
  int second = millis()/1000;
  disp1.write(second);
  disp1.clearDisp();

  disp2.write(999-second);
  disp2.clearDisp();
}
