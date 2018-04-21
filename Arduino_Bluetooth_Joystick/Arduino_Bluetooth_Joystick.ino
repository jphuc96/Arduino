int data;
int x,y;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  data = Serial.parseInt();
  switch(data){
    case 1:
    case 2:
    x = data;
    y = 0;
    break;
    
    case 3:
    case 4:
    x = 0;
    y = data;
    
    break;
    case 13:
    case 14:
    case 23:
    case 24:
    x = (data - (data%10))/10;
    y = data%10;
    break;
    
    case 31:
    case 32:
    case 41:
    case 42:
    y = (data - (data%10))/10;
    x = data%10;
    break;
    
    case 0:
    x = 0;
    y = 0;
    break;
  }
  if((x == 1) || (x == 2))
  digitalWrite(x+1,HIGH);
  else{
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  }
  
  if((y == 3) || (y == 4))
  digitalWrite(y+1,HIGH);
  else{
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  }
  
  Serial.print("Data: ");
  Serial.print(data);
  Serial.print("     X: ");
  Serial.print(x);
  Serial.print("     Y: ");
  Serial.print(y);
  Serial.println();
}
}
