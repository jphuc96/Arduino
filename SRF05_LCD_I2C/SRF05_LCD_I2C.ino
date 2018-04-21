
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN A1
#define ECHO_PIN A2
#define TIME_OUT 20000

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

char distanceChar;

float GetDistance()
{
  long duration, distanceCm;
   
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH, TIME_OUT);
 
  // convert to distance
  distanceCm = duration / 29.1 / 2;
  
  return distanceCm;
}
 
void setup() {  
  Serial.begin(9600);
 
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lcd.init();                      // initialize the lcd 

}
 
void loop() {
  long distance = GetDistance();
 
  if (distance > 0) 
  {  

    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Distance: ");
    lcd.setCursor(14,0);
    lcd.print("cm");

    if(distance>=100)
    {
    lcd.setCursor(10,0);
    }
    else if(distance>=10)
    {
    lcd.setCursor(10,0);
    lcd.print("0");
    lcd.setCursor(11,0);
    }
    else 
    {
    lcd.setCursor(10,0);
    lcd.print("00");
    lcd.setCursor(12,0);
    }
    
    lcd.print(distance);
    

  }
  else
  {
    lcd.setCursor(10,0);
    lcd.print("N/A");
  }
  delay(100);
}
