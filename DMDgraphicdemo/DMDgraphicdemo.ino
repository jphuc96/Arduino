#include <SPI.h>        //SPI.h must be included as DMD is written by SPI (the IDE complains otherwise)
#include <DMD2.h>        //
#include <TimerOne.h>   //
#include "SystemFont5x7.h"
#include "Arial_black_16.h"

//Fire up the DMD library as dmd
#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}

void setup()
{
  //initialize TimerOne's interrupt/CPU usage used to scan and refresh the display
  Timer1.initialize( 5000 );           //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
  Timer1.attachInterrupt( ScanDMD );   //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()
  //clear/init the DMD pixels held in RAM
  dmd.clearScreen( true );   //true is normal (all pixels off), false is negative (all pixels on)
  randomSeed(analogRead(0));
}

void loop()
{

  for (int a=0; a<5; a++)
  {
    for (int a=0; a<16; a++)
    {
      dmd.drawLine(  0, a, 31, a, GRAPHICS_NORMAL );
      delay(50);
      dmd.drawLine(  0, a, 31, a, GRAPHICS_NOR );    
    }
  }

  for (int a=0; a<5; a++)
  {
    for (int a=0; a<32; a++)
    {
      dmd.drawLine(  a, 0, a, 31, GRAPHICS_NORMAL );
      delay(50);
      dmd.drawLine(  a, 0, a, 31, GRAPHICS_NOR );    
    }
  }
  dmd.clearScreen( true );
  for (int a=0; a<5; a++)
  {
    for (int b=0; b<32; b++)
    {
      dmd.drawBox(0, 0, b, 15, GRAPHICS_NORMAL );
      delay(25);
      dmd.clearScreen( true );
    }
    for (int b=31; b>0; --b)
    {
      dmd.drawBox(0, 0, b, 15, GRAPHICS_NORMAL );
      delay(25);
      dmd.clearScreen( true );
    }
  }
  for (int a=0; a<5; a++)
  {
    for (int b=0; b<32; b++)
    {
      dmd.drawFilledBox(0, 0, b, 15, GRAPHICS_NORMAL );
      delay(25);
      dmd.clearScreen( true );
    }
    for (int b=31; b>0; --b)
    {
      dmd.drawFilledBox(0, 0, b, 15, GRAPHICS_NORMAL );
      delay(25);
      dmd.clearScreen( true );
    }

    // pixels 
    for (int qq=0; qq<5; qq++)
    {
      for (int z=0; z<16; z++)
      {
        for (int q=0; q<6; q++)
        {
          dmd.writePixel(  random(31),z, GRAPHICS_NORMAL,1); 
          delay(50);
        }
      }
    }   
    dmd.clearScreen( true );
    // circles
    for (int qqq=0; qqq<4; qqq++)
    {

      for (int z=0; z<32; z++)
      {
        dmd.drawCircle(z, 7, 5, GRAPHICS_NORMAL);
        delay(40);
        dmd.drawCircle(z, 7, 5, GRAPHICS_NOR);    
      }
      for (int z=30; z>0; --z)
      {
        dmd.drawCircle(z, 7, 5, GRAPHICS_NORMAL);
        delay(40);
        dmd.drawCircle(z, 7, 5, GRAPHICS_NOR);    
      }
    }
  }
}






