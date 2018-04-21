
 
#include <Servo.h>  

Servo myservo;          
int servoPin = 3;  

int data; // data[dir,spd,led out, led in,lock]: direction and speed

int dir,spd,led,lock;
int trigger1 = 0,trigger2 = 0;
#define BRAKEVCC 0
#define CW   1
#define CCW  2
#define BRAKEGND 3
#define CS_THRESHOLD 100
void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm);
void motorOff(int motor);
int inApin[2] = {7, 4};  // INA: Clockwise input
int inBpin[2] = {8, 9}; // INB: Counter-clockwise input
int pwmpin[2] = {5, 6}; // PWM input
//int cspin[2] = {2, 3}; // CS: Current sense ANALOG input
int enpin[2] = {0, 1}; // EN: Status of switches output (Analog pin)


void setup()  
{
  myservo.attach(servoPin); 
  pinMode(A5, INPUT);
  pinMode(A4, INPUT);
  pinMode(11,OUTPUT);

  Serial.begin(9600);
  delay(1000);
  Serial.println(F("Kho bau camping"));

 // Initialize digital pins as outputs
  for (int i=0; i<2; i++)
  {
    pinMode(inApin[i], OUTPUT);
    pinMode(inBpin[i], OUTPUT);
    pinMode(pwmpin[i], OUTPUT);
  }
  // Initialize braked
  for (int i=0; i<2; i++)
  {
    digitalWrite(inApin[i], LOW);
    digitalWrite(inBpin[i], LOW);
  } 
}
void loop() 
{
if(Serial.available()>0){
  data = Serial.parseInt();
  
    led = (data - data%100)/100;
    lock = (data -100*led)/10;
    dir = (data - 100*led - 10*lock);
    spd = 500;

    Serial.println(led);
    Serial.println(lock);
    Serial.println(dir);
    
    trigger1 = digitalRead(A5);
    trigger2 = digitalRead(A4);
//    
//    Serial.println();
//    Serial.println(dir);
//    Serial.println(spd);

    if(led==2)
      digitalWrite(11,LOW);
    if(led==1)
      digitalWrite(11,HIGH);
      
if(lock==1){

      myservo.write(120); //unlock
      digitalWrite(11,HIGH);
      
    switch(dir){
      
      case 1:  // mo thung     
      motorGo(0,CW,spd);
      delay(3500);
      motorOff(0);
      break;
      
      motorOff(0);     
      break;
      
      case 2:  // dong thung     
      motorGo(0,CCW,spd);
      delay(4500);
      motorOff(0);
      break;
      
      motorOff(0);
      break;
      
      default:
      motorOff(0);
      break;
  }
  } 
  if(lock==2)
    myservo.write(30); //lock
  }
}
void motorOff(int motor)
{
  // Initialize braked
  for (int i=0; i<2; i++)
  {
    digitalWrite(inApin[i], LOW);
    digitalWrite(inBpin[i], LOW);
  }
  analogWrite(pwmpin[motor], 0);
}

void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)
{
  if (motor <= 1)
  {
    if (direct <=4)
    {
      // Set inA[motor]
      if (direct <=1)
        digitalWrite(inApin[motor], HIGH);
      else
        digitalWrite(inApin[motor], LOW);

      // Set inB[motor]
      if ((direct==0)||(direct==2))
        digitalWrite(inBpin[motor], HIGH);
      else
        digitalWrite(inBpin[motor], LOW);

      analogWrite(pwmpin[motor], pwm);
    }
  }
}

