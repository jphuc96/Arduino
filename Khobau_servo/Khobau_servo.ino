#include <Servo.h>  
Servo myservo;          
int servoPin = 9;       // Khai báo chân điều khiển servo
 
void setup ()
{
    myservo.attach(servoPin); 
    
    Serial.begin(9600);
}
 
void loop ()
{
  if(Serial.available()>0){
    int value = Serial.parseInt();
    int servoPos = map(value, 0, 180, 0, 180);
    myservo.write(servoPos);
    Serial.println(servoPos);
}
}
