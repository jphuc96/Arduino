#include <Wire.h>
#include <MPU6050.h>
#include <PID_v1.h>

#define ena 9
#define in1 2
#define in2 3
#define adc_pin A0
#define CC 1
#define CCW 0
#define degconvert 57.2957786 //there are like 57 degrees in a radian.

MPU6050 mpu;
Vector rawAc,rawGy;

double PID_Setpoint, PID_Input, PID_Output;

double Kp=4.92, Ki=0.115, Kd=0.02875;
//double Kp=1.64, Ki=0.0925, Kd=0.069;

PID myPID(&PID_Input, &PID_Output, &PID_Setpoint, Kp, Ki, Kd, DIRECT);

double AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
double compAngleX, compAngleY; //These are the angles in the complementary filter
double roll, pitch;
double gyroXrate, gyroYrate;
double gyroXangle ,gyroYangle;
uint32_t timer;
uint32_t start_t;
void dir(bool mode);
void spd(int val);

void setup() {
/*Set up Part*/
pinMode(ena,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
Serial.begin(115200);

/*MPU6050 Part*/
Serial.println("Initialize MPU6050");
while(!mpu.begin(MPU6050_SCALE_500DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);  
  }
  //mpu.calibrateGyro(2000);
  
rawAc = mpu.readRawAccel();  
rawGy = mpu.readRawGyro();

roll = atan2(rawAc.YAxis, rawAc.ZAxis)*degconvert;
pitch = atan2(-rawAc.XAxis, rawAc.ZAxis)*degconvert;

  gyroXangle = roll;
  gyroYangle = pitch;
  compAngleX = roll;
  compAngleY = pitch;
  
  /*PID Part*/
  PID_Setpoint = map(analogRead(A0),0,1023,-90,90);
  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(10);
  myPID.SetOutputLimits(-255,255);

  timer = micros();
  start_t = micros();
}

void loop() {
  
  
  rawAc = mpu.readRawAccel();
  rawGy = mpu.readRawGyro();

  AcX = rawAc.XAxis;
  AcY = rawAc.YAxis;
  AcZ = rawAc.ZAxis;
  
  GyX = rawGy.XAxis;
  GyY = rawGy.YAxis;
  GyZ = rawGy.ZAxis;
  
  double dt = (double)(micros() - timer) / 1000000; //This line does three things: 1) stops the timer, 2)converts the timer's output to seconds from microseconds, 3)casts the value as a double saved to "dt".
  timer = micros(); //start the timer again so that we can calculate the next dt.

  roll = atan2(AcY, AcZ)*degconvert;
  pitch = atan2(-AcX, AcZ)*degconvert;

  gyroXrate = GyX/65.5;
  gyroYrate = GyY/65.5;

  compAngleX = 0.99 * (compAngleX + gyroXrate * dt) + 0.01 * roll; // Calculate the angle using a Complimentary filter
  compAngleY = 0.99 * (compAngleY + gyroYrate * dt) + 0.01 * pitch ; 
  
  PID_Setpoint = map(analogRead(A0),0,1023,-90,90);
  PID_Input = compAngleY;
  myPID.Compute();
  if(PID_Setpoint - PID_Input <= 0)  dir(CCW);
  else               dir(CC);
  spd(abs(PID_Output));

  // Serial Output
  Serial.print(220);
  Serial.print(" ");
  //Serial.print(pitch);
  Serial.print(" ");
  Serial.print(PID_Input);
  Serial.print(" ");
  Serial.print(PID_Setpoint);
  Serial.print(" ");
  Serial.print(-220);


  Serial.println(); 

}

void dir(bool mode){
  digitalWrite(in1,mode);
  digitalWrite(in2,!mode);
}

void spd(int val){
  if(val<=255)
  analogWrite(ena,val);
  else
  analogWrite(ena,255);
}

