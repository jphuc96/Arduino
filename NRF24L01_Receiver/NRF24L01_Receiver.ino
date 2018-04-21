#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

#define CE_PIN 7
#define CSN_PIN 8

const uint64_t pipe = 0xE8E8F0F0E1LL;

RF24 radio(CE_PIN,CSN_PIN);

int joystick[2];

void setup(){
  Serial.begin(9600);
  delay(1000);
  Serial.println("Receiver starting");
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
}
void loop()
{
  if (radio.available())
  {
    
      radio.read(joystick, sizeof(joystick));
      Serial.print("X = ");
      Serial.print(joystick[0]);
      Serial.print("Y = ");
      Serial.println(joystick[1]);     
    
  }
  else
  {
    Serial.println("No data");
  }
}

