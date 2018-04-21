#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space

// If you're not using the Ethernet W5100 shield, change this to match your connection type. See Communications examples.
#include <CayenneEthernet.h>
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

#include "DHT.h"

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "uupy7js8jb";

#define DHTPIN 23     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);

void CheckSensors();

void setup()
{
  Serial.begin(9600);
  Cayenne.begin(token);
  dht.begin();
}

void loop()
{
  Cayenne.run();
  
  CheckSensors();
  
}
unsigned long previousMillis = 0;

void CheckSensors()
{
  unsigned long currentMillis = millis();
  // Check sensor data every 250 milliseconds
  
  if (currentMillis - previousMillis >= 250) {
    /*Check Motion Sensor*/
    int motionState = digitalRead(22);
    /*Check DHT11 Sensor*/
    float tempVal = dht.readTemperature();
    float humiVal = dht.readHumidity();
    /*Check photoresistor*/
    float lightVal = (float)analogRead(A0)*100/1024;
    /*Check Door Trigger*/
    int doorState = digitalRead(24);
    /*Check Gas Sensor*/
    int gasVal = (float)analogRead(A8)*100/1024;
    
    Cayenne.virtualWrite(V0,motionState);
    Cayenne.virtualWrite(V1,tempVal);
    Cayenne.virtualWrite(V2,lightVal);
    Cayenne.virtualWrite(V3,humiVal);
    Cayenne.virtualWrite(V4,doorState);
    Cayenne.virtualWrite(V5,gasVal);
    
    previousMillis = currentMillis;
  }
}
