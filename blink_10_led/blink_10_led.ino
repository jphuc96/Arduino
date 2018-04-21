
int i;
uint16_t tick_Count = 0;
void setup() {
  // put your setup code here, to run once:
for(i=3;i<=12;i++)
{
  pinMode(i,OUTPUT);
}
}

void toggle_pin(int pin){
  digitalWrite(pin,!digitalRead(pin));
}
void update_status(uint16_t tick)
{
  if(tick%10==0) //update each1 1s
    toggle_pin(3);
}
void loop() {
  // put your main code here, to run repeatedly:
  tick_Count++;
  delay(1000);
}


