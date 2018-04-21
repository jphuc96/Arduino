
/*************MUST READ*************/
/* INCOME DATA MUST END WITH NEWLINE
 * SO THAT THE SYSTEM CAN DETECT THE CODE NUMBER
 */
 
#include <openGLCD.h>

boolean stringComplete = false;
String inputString = "";

int Command(uint16_t number);

void setup() {
  
  //Serial.begin(9600);

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

void loop() {
  if (stringComplete) {

    if(Command(0))  GLCD.println("Command 1"); //"001\n"
    if(Command(1))  GLCD.println("Command 2"); //"002\n"
    if(Command(2))  GLCD.println("Command 3"); //"003\n"
    if(Command(3))  GLCD.println("Command 4"); //"004\n"
    if(Command(4))  GLCD.println("Command 5"); //"005\n"
    
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

int Command(uint16_t number){
  if(inputString.toInt() == number){
    return 1;
  }
  else{
    return 0;
  }
    
}

