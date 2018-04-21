int i;
void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for(i=0;i<=10;i++){
  analogWrite(9,25*i);
  Serial.println(25*i);
  delay(700);
}
for(i=10;i>=0;i--){
  analogWrite(9,25*i);
  Serial.println(25*i);
  delay(700);
}
}
