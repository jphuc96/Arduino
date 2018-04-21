
const int stepPin = 3; 
const int dirPin = 4; 
int stepspeed = 50;
long angle=0,steps=0;
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  Serial.begin(9600);
  Serial.print("Enter angle: ");
}
void loop() {
  if(Serial.available()>0){
    angle = Serial.parseInt();
    steps = map(angle,0,360,0,3200);
    Serial.println(angle);
    Serial.print("Steps: ");
    Serial.println(steps);
    Serial.print("Enter angle: ");
  }
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(long x = 0; x < steps; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(stepspeed); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(stepspeed); 
  }
  delay(1000); // One second delay
  
  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(long x = 0; x < steps; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(stepspeed);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(stepspeed);
  }
  delay(1000);
}
