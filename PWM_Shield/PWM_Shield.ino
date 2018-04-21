#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  Serial.println("16 channel PWM test!");

  pwm.begin();
  pwm.setPWMFreq(200);  // This is the maximum PWM frequency
}

void loop() {
  // put your main code here, to run repeatedly:
pwm.setPWM(1,4095,4095);
}
