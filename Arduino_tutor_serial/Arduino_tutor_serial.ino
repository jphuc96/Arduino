int brightness = 0;
int value;
const int LED = 9;
void setup()
{
  Serial.begin(9600);
    Serial.print("enter brightness in percent: ");
}
void loop()
{

  if(Serial.available()>0)
  {
  brightness = Serial.parseInt();
  Serial.println(brightness); 
  value = map(brightness,0,100,0,255);
  analogWrite(LED,value);
  Serial.print("enter brightness in percent: ");
}
}

