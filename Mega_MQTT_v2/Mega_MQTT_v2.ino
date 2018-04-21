#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <Encoder.h>
#include <TimerThree.h>
#include <PID_v1.h>
#include <Servo.h>
#include <avr/wdt.h>
#include <stdlib.h>
#define DIRA 4
#define PWMA 5
#define IN1 5
#define IN2 6
#define ENA 7

#define soft_restart()        \
do                          \
{                           \
    wdt_enable(WDTO_15MS);  \
    for(;;)                 \
    {                       \
    }                       \
} while(0)

// Update these with values suitable for your network.
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ip(192, 168, 0, 103);

EthernetClient ethClient;
PubSubClient client(ethClient);

Servo myservo;
Encoder encoder(2, 3);
long lastPos = 0;
long currentPos = 0;
long rps = 0;
int servoPos = 0;

double Setpoint, Input, Output;
double Kp=1.2, Ki=1.8, Kd=0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void direct(int dir)
{
  //digitalWrite(DIRA,dir);
  digitalWrite(IN1,!dir);
  digitalWrite(IN2,dir);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  
  if(StrContains(topic,"Mega/setpoint")){
    Setpoint = (double)atoi((char*)payload);
    Serial.println(Setpoint);
  }
  if(StrContains(topic,"Mega/servo")){
    myservo.write(atoi((char*)payload));
  } 
  if(StrContains(topic,"Mega/reset")){
    soft_restart();
  } 
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    // Wait 3 seconds before retrying
      delay(3000);
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ArduinoMega")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("Mega/state","Arduino Mega Connected");
      // ... and resubscribe
      
      client.subscribe("Mega/servo");
      client.subscribe("Mega/setpoint");
      client.subscribe("Mega/reset");
      
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      
    }
  }
}

void timerIsr()
{
   Timer3.detachInterrupt();  //stop the timer
   currentPos = encoder.read();
   rps = (currentPos - lastPos)*100/(334*4);
   lastPos = currentPos;
   Input = rps;
   myPID.Compute();
   direct(1);
   analogWrite(ENA,(int)Output);
   Timer3.attachInterrupt( timerIsr );  //enable the timer
}

char StrContains(char *str, char *sfind)
{
    char found = 0;
    char index = 0;
    char len;

    len = strlen(str);
    
    if (strlen(sfind) > len) {
        return 0;
    }
    while (index < len) {
        if (str[index] == sfind[found]) {
            found++;
            if (strlen(sfind) == found) {
                return 1;
            }
        }
        else {
            found = 0;
        }
        index++;
    }

    return 0;
}

void setup()
{
  Serial.begin(115200);
 
  client.setServer("jphuc96.ddns.net", 1883);
  client.setCallback(callback);

  Ethernet.begin(mac, ip);

  Timer3.initialize(10000); // set timer for 10ms
  Timer3.attachInterrupt( timerIsr ); // enable the timer

  myservo.attach(9);
  myservo.write(1);
  
  //pinMode(DIRA,OUTPUT);
  //pinMode(PWMA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);
  
  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(10);
  // Allow the hardware to sort itself out
  delay(1500);
}

uint32_t previousMillis = 0;
uint32_t currentMillis = 0;
char speed_buf[10];
char OutputBuf[10];
void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  currentMillis = millis();
  if(currentMillis - previousMillis >= 500){
    sprintf(speed_buf,"%d",rps);
    sprintf(OutputBuf,"%d",(int)Output);
    client.publish("Mega/Output",OutputBuf);
    client.publish("Mega/speed",speed_buf);
    //Serial.println(Setpoint);
    previousMillis = currentMillis;
  }
  client.loop();
}
