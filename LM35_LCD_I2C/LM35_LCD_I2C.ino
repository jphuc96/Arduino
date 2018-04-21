
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
float tempC;
float reading;
int tempPin = A0;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address 

void setup()
{
//analogReference(INTERNAL);
Serial.begin(9600);
lcd.begin(16,2);
  lcd.backlight();
  
  
}

void loop()
{
reading = analogRead(tempPin);
tempC = reading;
//Serial.println(tempC);
lcd.setCursor(0,0);
lcd.print("Temp: ");
lcd.print(tempC);
lcd.print("*C");
delay(500);
lcd.clear();
}
