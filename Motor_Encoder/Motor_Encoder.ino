#define dirA 4
#define pwmA 5
#define pwmB 6
#define dirB 7
#define encoderA 2

int count=0;
long Time1 = 0;
long Time2 = 0;
long Time3 = 0;

int i;
void setup() {

Serial.begin(9600);

pinMode(dirA,OUTPUT);
pinMode(dirB,OUTPUT);
pinMode(pwmA,OUTPUT);
pinMode(pwmB,OUTPUT);
pinMode(encoderA,INPUT_PULLUP);
pinMode(3,INPUT_PULLUP);

attachInterrupt(0, pulse, FALLING);

}

void pulse(){
  count++;
}

void RPM(){
  count = 0;
  delay(10); // get pulses read every 10ms
  int p = count;
  count = 0;

   Serial.print("RPM: ");
   Serial.println(p*18);
   // Explain:
   // Let p = the pulses read every 10ms
   // => 100*p every second
   // => 60*100*p every minute
   // The encoder resolution is 334 pulse per round (ppr)
   // So the Round per Minute (RPM) is (60*100*p)/334 ~ 18*p
  
}
void loop() {
digitalWrite(dirA,0);
for(i=0;i<=255;i+=5){
analogWrite(pwmA,i);
RPM();
delay(100);
}
delay(1000);
for(i=255;i>=0;i-=5){
analogWrite(pwmA,i);
RPM();
delay(100);
}
}
