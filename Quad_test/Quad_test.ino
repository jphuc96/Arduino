#include <Wire.h>
#include <MPU6050.h>
#include <PID_v1.h>

#define motor1 9
#define motor2 10
#define degconvert 57.2957786 //there are like 57 degrees in a radian.


/*PID variables*/
double PID_Setpoint, PID_Input, PID_Output;
double Kp=5, Ki=0.0, Kd=0.0;
PID myPID(&PID_Input, &PID_Output, &PID_Setpoint, Kp, Ki, Kd, DIRECT);

/*MPU6050 variables*/
MPU6050 mpu;
Vector rawAc,rawGy;
double AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
double compAngleX, compAngleY; //These are the angles in the complementary filter
double roll, pitch;
double gyroXrate, gyroYrate;
double gyroXangle ,gyroYangle;
uint32_t timer;
uint32_t start_t;

void setup() {
  // put your setup code here, to run once:
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
Serial.begin(115200);

/*PID Part*/
  PID_Setpoint = 0;
  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(10);
  myPID.SetOutputLimits(-20,20);

  
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
  // Calculate the angle using a Complimentary filter
  compAngleX = 0.99 * (compAngleX + gyroXrate * dt) + 0.01 * roll; 
  compAngleY = 0.99 * (compAngleY + gyroYrate * dt) + 0.01 * pitch ; 

  
  int spd = map(analogRead(A0),0,1023,0,255);

  PID_Input = compAngleX;
  myPID.Compute();
  if(PID_Setpoint - PID_Input >= 0){
    analogWrite(motor1,spd-PID_Output);
    analogWrite(motor2,spd);
  }
  else{
    analogWrite(motor1,spd);
    analogWrite(motor2,spd+PID_Output);
  }
  
  Serial.print(90);
  Serial.print(" ");
  Serial.print(PID_Setpoint);
  Serial.print(" ");
  Serial.print(PID_Input);
  Serial.print(" ");
  Serial.print(PID_Output);
  Serial.print(" ");
  Serial.print(-90);
  Serial.print(" ");
  Serial.println();

/*
  Serial.print(spd1);
  Serial.print("   ");
  Serial.print(spd2);
  Serial.println();
  */
}
