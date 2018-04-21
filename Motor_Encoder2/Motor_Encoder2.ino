#include <TimerThree.h>
#include <Encoder.h>
#include <PID_v1.h>

#define IN1 5
#define IN2 6
#define ENA 7

Encoder encoder(2,3);
long lastPos = 0;
long currentPos = 0;
long rps = 0;

double Setpoint, Input, Output;
double Kp=2, Ki=5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void direct(int dir)
{
  digitalWrite(IN1,dir);
  digitalWrite(IN2,!dir);
}

void timerIsr()
{
  Timer3.detachInterrupt();  //stop the timer
  currentPos = encoder.read();
  rps = (currentPos - lastPos)*100/(334*4);
  lastPos = currentPos;

  Timer3.attachInterrupt( timerIsr );  //enable the timer
}

void setup() 
{
  Serial.begin(115200);

  Timer3.initialize(10000); // set timer for 10ms
  Timer3.attachInterrupt( timerIsr ); // enable the timer
} 


void loop() {
  Serial.print("Round per Second: "); 
  Serial.println(rps);
  delay(1000);
}
