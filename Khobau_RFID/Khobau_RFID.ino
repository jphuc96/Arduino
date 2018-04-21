// variables to keep state
int readVal = 0; // individual character read from serial
unsigned int readData[10]; // data read from serial
int counter = -1; // counter to keep position in the buffer
char tagId[11]; // final tag ID converted to a string
long tagId_dec;
//guide 5
long authorizedTags[26]={
11690612,
11690609,
11690546,
11714619,
11714687,
11678945,
11690811,
11691005,
11690802,
11690789,
11690780,
11690983,
11680467,
11690758,
11690714,
11690400,
11701256,
11701249,
11842136,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647
}; // array to hold the list of authorized tags



void setup() {                
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);

}

// check if the tag ID we just read is any of the authorized tags
int checkTag() {

  int i;
  for (i = 0; i < 26; ++i) {
    if (tagId_dec == authorizedTags[i]) {
      return 1;
    }
  }
  return 0;
}

// convert the int values read from serial to ASCII chars
void parseTag() {
  int i;
  for (i = 0; i < 10; ++i) {
    tagId[i] = readData[i];
  }
  tagId[10] = 0;
  //convert hex string into long decimal
  String hexstring = String(tagId);
  tagId_dec = strtol(hexstring.c_str(), NULL, 16);
}

// once a whole tag is read, process it
void processTag() {
  // convert id to a string
  parseTag();
  // print it
}

void printTag() {
  Serial.print("Tag value: ");
  
  Serial.println(tagId_dec);
}

// perform an action when an authorized tag was read
void tagSuccess() {
  Serial.println("Tag authorized.");
  delay(500);
}
// inform the user that the tag is not authorized
void tagFailed() {
  Serial.println("Unauthorized access!");
  delay(500);
}

// this function clears the rest of data on the serial, to prevent multiple scans
void clearSerial() {
  while (Serial.read() >= 0) {
    ; // do nothing
  }
}

long readTag(){
  while (Serial.available() > 0) {
  delay(100);
  digitalWrite(7,HIGH);

  // read the incoming byte:
     int value = Serial.read();
  // a "2" signals the beginning of a tag
    if (value == 2) {
      counter = 0; // start reading
    } 
    // a "3" signals the end of a tag
    else if (value == 3) {
      // process the tag we just read
      processTag();
      
      // clear serial to prevent multiple reads
      clearSerial();
      
      // reset reading state
      counter = -1;
    }
    // if we are in the middle of reading a tag
    else if (counter >= 0) {
      // save valuee
      readData[counter] = value;
       
      // increment counter
      ++counter;
    }
  }
  digitalWrite(7,LOW);
  return tagId_dec;
  clearSerial();
}

void winner(){
  digitalWrite(7,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
    while(1){
  digitalWrite(9,HIGH);
  delay(100);
  digitalWrite(9,LOW);
  delay(100);
    }
}
void loop() {
  digitalWrite(12,LOW);
  int tag1 = digitalRead(2);
  int tag2 = digitalRead(3);
  int tag3 = digitalRead(4);
  int tag4 = digitalRead(5);
  
  if(Serial.available()>0){
 long ID = readTag();
  if(checkTag()==1 && tag1==1 && tag2==1 && tag3==1 && tag4==1){
  winner();
  }
  else{  
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}
  }
}

