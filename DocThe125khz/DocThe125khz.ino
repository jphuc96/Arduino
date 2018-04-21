int data = 0;
char input[14];
char key[14] = {2,50,50,48,48,53,70,49,57,50,50,52,54,3};
void setup()
{
Serial.begin(9600);
}
void loop()
{
  while(Serial.available() > 0) {
    Serial.flush();
for(int i=0;i<=13;i++){
data = Serial.read();
input[i] = data;
Serial.print(input[i]);
//Serial.print(data);
Serial.print(" ");
}
Serial.println();
}
}
