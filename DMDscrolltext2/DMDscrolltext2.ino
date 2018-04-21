/*
  Scrolling alphabet demo, displays characters one at a time into a scrolling box.
 */

#include <SPI.h>
#include <DMD2.h>
#include <fonts/SystemFont5x7.h>
#include <fonts/Arial_black_16.h>

// Set Width to the number of displays wide you have
const int WIDTH = 2;

// You can change to a smaller font (two lines) by commenting this line,
// and uncommenting the line after it:
//const uint8_t *FONT = Arial_black_16;
//const uint8_t *FONT = SystemFont5x7;

const char *MESSAGE = "School of Electrical Engineering";

SoftDMD dmd(WIDTH,1);  // DMD controls the entire display
DMD_TextBox box(dmd);  // "box" provides a text box to automatically write to/scroll the display

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  dmd.setBrightness(50);
  dmd.selectFont(Arial_Black_16);
  dmd.begin();
}

// the loop routine runs over and over again forever:
void loop() {
  const char *next = MESSAGE;
  long timer = millis();
  while(*next) {
     if ((timer+30) < millis()) {
    Serial.print(*next);
    box.print(*next);
    next++;
    timer=millis();
     }
  }
  delay(2000);
}
