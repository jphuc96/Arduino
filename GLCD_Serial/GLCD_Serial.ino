
#include <openGLCD.h>
void setup() {
  // Initialize the GLCD 
  GLCD.Init();
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
 // Select the font for the default text area
  
  GLCD.SelectFont(Arial14); 
  GLCD.println("   DAI HOC QUOC TE");
  GLCD.SelectFont(System5x7);
  GLCD.println("         Khoa");
  GLCD.println("  Dien Tu-Vien Thong");
  GLCD.SelectFont(Arial_bold_14);
  GLCD.println("       DAKHA 01");
  GLCD.SelectFont(System5x7);
  GLCD.println();
  GLCD.println("Listening...");
  delay(1500);
  Serial.begin(9600);
  while(!Serial.available());
  GLCD.ClearScreen();
}
void loop()
{
char c;
  if (Serial.available())
  {   
      c = Serial.read();
      GLCD.write(c);
  }
}
