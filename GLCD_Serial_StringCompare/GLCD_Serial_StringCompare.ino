
boolean stringComplete = false;
String inputString = "";
int Command(uint16_t number);
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (stringComplete) {
    if(Command(0))  Serial.println("System Reset");
    if(Command(1))  Serial.println("Task1");
    if(Command(2))  Serial.println("Task2");
    if(Command(3))  Serial.println("Task3");
    if(Command(4))  Serial.println("IDLING...");
    
    
    
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

