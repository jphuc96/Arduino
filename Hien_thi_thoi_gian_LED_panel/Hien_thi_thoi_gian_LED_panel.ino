#include <DMD.h>
#include <SPI.h>
#include <TimerOne.h> 
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
#define DISPLAYS_ACROSS 2 
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);
String tiktok = ":";
//RTC setup
#include "Wire.h"
#define DS3231_I2C_ADDRESS 0x68
  byte x,y;
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  String thu;
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}
//RTC_setup



void ScanDMD() // necessary interrupt handler for refresh scanning of DMD
{ 
  dmd.scanDisplayBySPI();
  dmd.setBrightness(254);
}

void setup() {
  dmd.selectFont(System5x7);
  //initialize TimerOne's interrupt/CPU usage used to scan and refresh the display
   Timer1.initialize( 5000 );           //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
   Timer1.attachInterrupt( ScanDMD );   //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()  
   dmd.clearScreen( true );   //true is normal (all pixels off), false is negative (all pixels on)
  Wire.begin();
  Serial.begin(9600);
  
  // set the initial time here:
  // DS3231 seconds, minutes, hours, day, date, month, year
   //setDS3231time(00,19,15,2,19,9,16);
}

void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year)
{
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
}
void readDS3231time(byte *second,
byte *minute,
byte *hour,
byte *dayOfWeek,
byte *dayOfMonth,
byte *month,
byte *year)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}
void loop() {

  
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,&year);
  String giay  = String(second,    DEC);
  String phut  = String(minute,    DEC);
  String gio   = String(hour,      DEC);
  String thu   = String(dayOfWeek, DEC);
  String ngay  = String(dayOfMonth,DEC);
  String thang = String(month,     DEC);
  String nam   = String(year+2000, DEC);

switch(dayOfWeek){
  case 1:
    thu = "Sun";
  break;
  case 2:
    thu = "Mon";
    break;
  case 3:
    thu = "Tue";
    break;
  case 4:
    thu = "Wed";
    break;
  case 5:
    thu = "Thu";
    break;
  case 6:
    thu = "Fri";
    break;
  case 7:
    thu = "Sat";
    break;
}

if(hour<10)
  gio = "0" + gio;
if(minute<10)
  phut = "0" + phut;
if(dayOfMonth<10)
  ngay = "0" + ngay;
if(month<10)
  thang = "0" + thang;
if(second<10)
  giay = "0" + giay;
  
tiktok = ":";
String dong1 = gio + tiktok + phut + " " + thu;
       
String dong2 = ngay + "/" + thang + "/" + nam;
       x=0;y=0;
       dmd.drawString(  (32*x),   (16*y) , &dong1[0] , 10, GRAPHICS_NORMAL );
       dmd.drawString(  (32*x), 8+(16*y) , &dong2[0] , 10, GRAPHICS_NORMAL );
       delay(1000);
       
tiktok = " ";
dong1 = gio + tiktok + phut + " " + thu;
       dmd.drawString(  (32*x),   (16*y) , &dong1[0] , 10, GRAPHICS_NORMAL );
       delay(1000);
       
}
