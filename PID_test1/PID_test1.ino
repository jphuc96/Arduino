/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>

#define PIN_INPUT 0
#define PIN_OUTPUT 9

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=1, Ki=0.5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Input = analogRead(PIN_INPUT);
  Setpoint = 100;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(20);
  myPID.SetOutputLimits(0,100);
  Serial.begin(115200);
}

void loop()
{
  Input = map(analogRead(PIN_INPUT),0,1023,0,255);
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);
  Serial.print(0);  // To freeze the lower limit
  Serial.print(" ");
  Serial.print(300);  // To freeze the upper limit
  Serial.print(" ");
  
  Serial.print(Input);
  Serial.print("  ");
  Serial.print(Setpoint);
  Serial.print("  ");
  Serial.println(Output);
  delay(10);
}


