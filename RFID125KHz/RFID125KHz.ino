int newtag[5] = {0,0,0,0,0};
int tag1[5]={0,80,216,171,35};
int tag2[5]={0,80,196,119,226};
int ok;
void setup()
{
  Serial.flush();
Serial.begin(9600);
pinMode(3, OUTPUT);
pinMode(13, OUTPUT);
}
boolean compare(int aa[5], int bb[5]) //compare function
{
boolean ff = false;
int fg = 0;
for (int cc = 0 ; cc < 5 ; cc++)
{
if (aa[cc] == bb[cc])
{
fg++;
}
}
if (fg == 5)
{
ff = true;
}
return ff;
}
void checktags() // check whether it had a match
{
ok = 0; 
if (compare(newtag, tag1) == true)
{
 ok++;
}
if (compare(newtag, tag2) == true)
{
 ok++;
}
}
void loop()
{
ok = -1;
if (Serial.available() > 0)
delay(100); 
//read new tag
for (int z = 0 ; z < 5 ; z++)
 {
int data = Serial.read();
newtag[z] = data;
}
Serial.flush(); 
//end reading tag
checktags();
if (ok > 0) // if match
{
Serial.println("Accepted");
ok = -1;
digitalWrite(13, HIGH);
digitalWrite(3, LOW);
}
else if (ok == 0) // if no match
{
Serial.println("Rejected");
ok = -1;
digitalWrite(3, HIGH);
digitalWrite(13, LOW);
}
}

