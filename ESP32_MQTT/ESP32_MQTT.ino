#include <WiFi.h>
#include <PubSubClient.h>
#include <PID_v1.h>

#include <driver/adc.h>
/*
const char ssid[] = "WIFIFREE2";
const char pass[] = "hoilamchi";
*/
const char ssid[] = "International University 3B";
const char pass[] = "hcmiu3bltt";

WiFiClient net;
PubSubClient client(net);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  char c[1];
  c[0] = payload[0];
  int PinState = atoi(c);
  Serial.print("Update Pin ");
  Serial.print(getPin(topic));
  Serial.print(" to ");
  Serial.println(PinState);
  digitalWrite(getPin(topic),PinState);

}

int getPin(const char* str){
  char PinStr[2];
  uint16_t lastSlash;
  for(int i=0;i<strlen(str);i++){
    if(str[i]=='/'){
      lastSlash = i;
    }
  }
  PinStr[0] = str[lastSlash+1];
  PinStr[1] = str[lastSlash+2];
  return atoi(PinStr);
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    // Wait 2 seconds before retrying
    delay(5000);
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("ESP32/state","ESP32 Connected");
      // ... and resubscribe
      client.subscribe("ESP32/GPIO/21");
      client.subscribe("ESP32/GPIO/22");
      client.subscribe("ESP32/GPIO/23");
      
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 3 seconds");
      
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  
  client.setServer("jphuc96.ddns.net", 1883);
  client.setCallback(callback);

  pinMode(21,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  
  adc1_config_width(ADC_WIDTH_12Bit);
  adc1_config_channel_atten(ADC1_CHANNEL_0,ADC_ATTEN_11db);

}

uint32_t previousMillis = 0;
uint32_t currentMillis = 0;
uint16_t servoVal = 0;
uint16_t servoStep = 10;
char servoBuf[10];
void loop() {
  // put your main code here, to run repeatedly:
  if (!client.connected()) {
    reconnect();
  }
  
  currentMillis = millis();
  if(currentMillis - previousMillis > 1000){
    sprintf(servoBuf,"%d",servoVal);
    client.publish("Mega/servo",servoBuf);
    if(servoVal==90){
      servoStep=-10;
    }
    if(servoVal==0){
      servoStep=10;
    }
    servoVal+=servoStep;
    
    previousMillis = currentMillis;
  }
  
  client.loop();


}
