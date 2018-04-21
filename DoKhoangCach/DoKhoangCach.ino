#define TRIG_PIN 2
#define ECHO_PIN 3
#define TIME_OUT 20000
 
float GetDistance()
{
  long duration, distanceCm;
   
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH, TIME_OUT);
 
  // convert to distance
  distanceCm = duration / 29.1 / 2;
  
  return distanceCm;
}
 
void setup() {  
  Serial.begin(9600);
 
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}
 
void loop() {
  long distance = GetDistance();
 
  if (distance <= 0)
  {
    Serial.println("Echo time out !!");
  }
  else
  {   
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm");
    Serial.println();
  }
  delay(100);
}
