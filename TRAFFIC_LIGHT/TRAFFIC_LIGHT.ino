#include <SevenSeg.h>
SevenSeg disp1(6,7,8,9,10,11,12);
SevenSeg disp2(6,7,8,9,10,11,12);

const int numOfDigits1 = 2;
const int numOfDigits2 = 2;

int digitPins1[numOfDigits1]={0,1};
int digitPins2[numOfDigits2]={2,3};

int countdown(int n){
  
 int t = (millis()%((n+1)*1000))/1000;
  return n-t;
}

int r,g,y;
int a=1;
int totaltime;
 
void setup() {
  // put your setup code here, to run once:
  disp1.setDigitPins(numOfDigits1,digitPins1);
  disp1.setDigitDelay(1667);
  disp2.setDigitPins(numOfDigits2,digitPins2);
  disp2.setDigitDelay(1667);
  
}

void loop() {
  // put your main code here, to run repeatedly:

r=1;
g=1;
y=1;
totaltime = countdown(30);
while(r>0){
  r=countdown(totaltime-15);
  disp1.write(r);
}

while(g>0){
  g=countdown(totaltime-5);
  disp1.write(g);
}


while(y>0){
  y=countdown(totaltime);
  disp1.write(y);
}
}
