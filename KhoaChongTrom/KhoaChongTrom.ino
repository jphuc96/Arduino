#include <EEPROM.h>
int admincount=0;
int ok;
int a1,b1,c1,d1,e1,a2,b2,c2,d2,e2;
int newtag[5] = {0,0,0,0,0};
int admin[5]={0,80,234,159,37};
unsigned long time;
int count=0;
void setup()
{
  Serial.flush();
Serial.begin(9600);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
pinMode(11, OUTPUT);

//BAO DONG:
    while(Serial.available()==0){
      time=millis();
      if(time>3000){
    digitalWrite(12, HIGH);
      }
  }
  
}

boolean comparetag(int aa[5], int bb[5])
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

void checkmytags()
{
a1=EEPROM.read(0);
b1=EEPROM.read(1);
c1=EEPROM.read(2);
d1=EEPROM.read(3);
e1=EEPROM.read(4);
a2=EEPROM.read(5);
b2=EEPROM.read(6);
c2=EEPROM.read(7);
d2=EEPROM.read(8);
e2=EEPROM.read(9);

int tag1[5]={a1,b1,c1,d1,e1};
int tag2[5]={a2,b2,c2,d2,e2};

ok = 0; 
if (comparetag(newtag, tag1) == true)
{
 ok++;
}
if (comparetag(newtag, tag2) == true)
{
 ok++;
}
if (comparetag(newtag, admin) == true)
{
 ok++;
 admincount++;

 Serial.println(admincount);
}
}


void changetags()
{
        
Serial.print("Write tag 1");
Serial.println();
delay(3000);


if(Serial.available()>0){
  delay(100);
  Serial.flush();
 for (int z = 0 ; z < 5 ; z++)
{
int data = Serial.read();
EEPROM.write(z, data);
Serial.print("Writing value ");
Serial.print(z);
Serial.println();
delay(50);
}
digitalWrite(11, HIGH);
delay(300);
digitalWrite(11, LOW);
Serial.println("Finished");
}
}


void readtags()
{
  Serial.flush();
if (Serial.available() > 0)
{
  delay(100);
for (int z = 0 ; z < 5 ; z++)
{
int data = Serial.read();
newtag[z] = data;
}  
Serial.flush(); 
checkmytags();

}
}

void admincheck()
{

while(Serial.available()==0);

if(admincount==2){
    digitalWrite(11, HIGH);
    delay(100);
    digitalWrite(11, LOW);
    delay(100);
    digitalWrite(11, HIGH);
    delay(100);
    digitalWrite(11, LOW);

    changetags();
}

}

void loop()
{
ok = -1;
readtags();

if ((ok > 0)) // if we had a match
{
Serial.println("Accepted");
digitalWrite(12, LOW);
ok = -1;
digitalWrite(13, HIGH);
admincheck();
}
else if (ok == 0) // if we didn't have a match
{
Serial.println("Rejected");
ok = -1;
digitalWrite(13, LOW);
}

}



