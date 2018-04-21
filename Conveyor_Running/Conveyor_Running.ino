
#define start_sw  12
#define stop_sw   6
#define led_1     11
#define led_2     10
#define led_3     9
#define led_4     8
#define led_5     7

uint32_t start_time;

void turn_on();
void turn_off();

void setup() {
  // put your setup code here, to run once:
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(led_3,OUTPUT);
  pinMode(led_4,OUTPUT);
  pinMode(led_5,OUTPUT);
  pinMode(start_sw,INPUT);
  pinMode(stop_sw,INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  start_time = millis();
  while(digitalRead(start_sw) == HIGH){
    if(millis()-start_time > 10000){
      turn_off();
    }
  }
  turn_on();
}
void turn_on()
{
  delay(1000);
  digitalWrite(led_1,HIGH);  
  delay(1000);
  digitalWrite(led_2,HIGH); 
  delay(1000);
  digitalWrite(led_3,HIGH); 
  delay(1000);
  digitalWrite(led_4,HIGH); 
  delay(1000);
  digitalWrite(led_5,HIGH);
}
void turn_off()
{
  delay(100);
  digitalWrite(led_1,LOW);  
  delay(100);
  digitalWrite(led_2,LOW); 
  delay(100);
  digitalWrite(led_3,LOW); 
  delay(100);
  digitalWrite(led_4,LOW; 
  delay(100);
  digitalWrite(led_5,LOW);
}
