#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Celcius Scale");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int ADC_val = analogRead(A0);
  float tempC = (float)ADC/11.5;
  Serial.println(tempC);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print("*C");
  //delay(500);
}
