int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

const int seg[10] = {
  0b11000000,//0 
  0b11111001,//1 
  0b10100100,//2
  0b10110000,//3
  0b10011001,//4
  0b10010010,//5
  0b10000010,//6
  0b11111000,//7
  0b10000000,//8
  0b10010000,//9
};


void setup() {
  
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() { 
 for(int j =0; j<=9;j++){ 
    
 for(int i = 0;i<=9;i++){  
    digitalWrite(latchPin, LOW);   
    shiftOut(dataPin, clockPin, MSBFIRST, seg[j]);  
    shiftOut(dataPin, clockPin, MSBFIRST, seg[i]);    
    digitalWrite(latchPin, HIGH);
    delay(500);    
 }
 }
 }

