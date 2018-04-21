
#define start_sw  12
#define stop_sw   6
#define led_1     11
#define led_2     10
#define led_3     9
#define led_4     8
#define led_5     7

uint32_t start_time;
uint32_t stop_time;

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
  int sec = 0;
  Serial.println("Waiting to start...");
  while(digitalRead(start_sw) == HIGH);
  Serial.println("Start Counting Time");
  start_time = millis();

  while(digitalRead(stop_sw) == HIGH){
    if(millis()%1000==0){
      sec++;
      Serial.print("Time: ");
      Serial.print(sec);
      Serial.println(" s");
    }
  }
  
  Serial.println("Stop Counting Time");
  stop_time = millis();
  Serial.print("Time from Start to Stop: ");
  Serial.print((stop_time-start_time));
  Serial.println(" ms");
}


