int enA = 8, in1 = 7, in2 = 6; //Configuration for Motor A
int enB = 3, in3 = 5, in4 = 4; // Config. for Motor B
int i;

void setup()
{
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);

Serial.begin(9600);
Serial.print("Enter speed level (-100 to 100): ");
}

void chaymotor(){
for(i=0;i<=255;i++) //Te sting the motors to max value
{
digitalWrite(in3, HIGH);
digitalWrite(in1, HIGH);
digitalWrite(in4, LOW);
digitalWrite(in2, LOW);
analogWrite(enB, i);
analogWrite(enA, i);
delay(100);
}
for(i=255;i>=0;i--) //Testing the motors to min value
{
digitalWrite(in3, HIGH);
digitalWrite(in1, HIGH);
digitalWrite(in4, LOW);
digitalWrite(in2, LOW);
analogWrite(enB, i);
analogWrite(enA, i);
delay(100);
}
}

void motorGo(int huong, int tocdo){
  
    if(huong==1){
      digitalWrite(in1,HIGH);   //Forward configuration 
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      analogWrite(enA,tocdo);   //Speed control 
      analogWrite(enA,tocdo);    
   }
   if(huong==2){                       
      digitalWrite(in1,LOW);    //Backward configuration
      digitalWrite(in2,HIGH);  
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      analogWrite(enB,tocdo);   //Speed control
      analogWrite(enB,tocdo);
    }
}

void loop()
{
if(Serial.available()>0){
  int percent = Serial.parseInt();
  Serial.println(percent);
  
  int value = map(percent,-100,100,-255,255);
  if(value>=0)
  motorGo(1,value);
  if(value<=0)
  motorGo(2,-value);
  Serial.print("Enter speed level (-100 to 100): ");
}
}

