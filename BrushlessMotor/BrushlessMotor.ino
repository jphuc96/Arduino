
int value = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
value = analogRead(A0);
Serial.println(value);

analogWrite(9, map(value,0,1023,0,255));

}
