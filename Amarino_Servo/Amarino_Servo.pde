#include <Servo.h>
#include <MeetAndroid.h>

float data[3] = {0};
int intdata[3] = {0};
int i = 1;
Servo myservo;
int pos = 0;

// MeetAndroid meetAndroid();
// you can define your own error function to catch messages
// where not fuction has been attached for
MeetAndroid meetAndroid(error);

void error(uint8_t flag, uint8_t values){
  Serial.print("ERROR: ");
  Serial.print(flag);
}

 
  void setup() {
  Serial.begin(9600); //begin serial link @ 9600bps
  // register callback functions, which will be called when an associated event occurs.
  // - the first parameter is the name of your function (see below)
  // - match the second parameter ('A', 'B', 'a', etc...) with the flag on your Android application
  meetAndroid.registerFunction(floatValues, 'A');  
  myservo.attach(11); //Attach the servo to pin eleven

}

void loop()
{
  meetAndroid.receive(); // you need to keep this in your loop() to receive events 
}
void floatValues(byte flag, byte numOfValues)
{
  // create an array where all event values should be stored
  // the number of values attached to this event is given by
  // a parameter(numOfValues)
  
  // call the library function to fill the array with values (floats)
  meetAndroid.getFloatValues(data);
  

  for (int i=0; i<3;i++)
  {
    meetAndroid.send(data[i]);//Used for debug purposes
  }

  if (-10<=data[1]<=10)   {
     intdata[1] = int(data[1]); //Cast the X axis float value to int
     intdata[1] = intdata[1]+10;
     pos = intdata[1]*9;
     myservo.write(pos);
  }
   
            
}

