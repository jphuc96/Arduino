// variables to keep state
int readVal = 0; // individual character read from serial
unsigned int readData[10]; // data read from serial
int counter = -1; // counter to keep position in the buffer
char tagId[11]; // final tag ID converted to a string
long tagId_dec;
// guide 1 data
long authorizedTags_0[26]={
2147483647,
11837536,
11714638,
11714660,
11690381,
11690403,
11683341,
11683322,
11683300,
11683363,
11683366,
11683385,
11683388,
11683227,
11714540,
11714641,
11714663,
11714684,
11714707,
11684189,
11684145,
11684198,
11684132,
11684154,
11684101,
11683297};
//guide 2 data
long authorizedTags_1[26]={
11823323,
11716027,
11716037,
11683278,
11683344,
11690590,
11690587,
11690568,
11690565,
11684088,
11684110,
11684167,
11684176,
11684079,
11684123,
11683908,
11683899,
11683921,
11701388,
11701381,
11716014,
11837531,
11820944,
11842131,
11820925,
11842114};

//guide 3 data
long authorizedTags_2[26]={
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647
};
//guide 4
long authorizedTags_3[26]={
11701234,
11701278,
11690358,
11701271,
11701315,
11701300,
11701293, 
11683287,
11690974,
11690996,
11714537,
11842153,
11842158,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
2147483647,
11837492,
11837306,
11837311,
11837328,
11837514,
11837509,
11837553
};

void setup() {                
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
 // initAuthorizedTags();
  
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  pinMode(31,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(35,OUTPUT);
  pinMode(37,OUTPUT);
 
}

// check if the tag ID we just read is any of the authorized tags
int checkTag(int opt) {
  int i;
  switch(opt){
    case 0:
  for (i = 0; i < 26; ++i) {
    if (tagId_dec == authorizedTags_0[i]) {
      return 1;
    }
  }
  return 0;
  break;
  
    case 1:
    for (i = 0; i < 26; ++i) {
    if (tagId_dec == authorizedTags_1[i]) {
      return 1;
      break;
    }
    }
  return 0;
  break;
  
  case 2:
  for (i = 0; i < 26; ++i) {
    if (tagId_dec == authorizedTags_2[i]) {
      return 1;
      break;
    }
  }
  return 0;
  break;

  case 3:
  for (i = 0; i < 26; ++i) {
    if (tagId_dec == authorizedTags_3[i]) {
      return 1;
      break;
    }
  }
  return 0;
  break;
  
  }
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
// perform an action when an authorized tag was read
void tagSuccess() {
  Serial.println("Tag authorized.");
  delay(50);
}
// inform the user that the tag is not authorized
void tagFailed() {
  Serial.println("Unauthorized access!");
}

// this function clears the rest of data on the serial, to prevent multiple scans
void clearSerial() { 
  while (Serial.read() >= 0) {
    ; // do nothing
  }
}

long readTag(int opt){
  switch(opt){
    case 0:
  while (Serial.available() > 0) {
    digitalWrite(31,HIGH);
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
      // reset reading state
      counter = -1;
      break;
    }
    // if we are in the middle of reading a tag
    else if (counter >= 0) {
      // save valuee
      readData[counter] = value;
       
      // increment counter
      ++counter;
    }
  }
  digitalWrite(31,LOW);
  return tagId_dec;
  break;

  case 1:
    while (Serial1.available() > 0) {
      digitalWrite(33,HIGH);
  // read the incoming byte:
     int value = Serial1.read();
  // a "2" signals the beginning of a tag
    if (value == 2) {
      counter = 0; // start reading
    } 
    // a "3" signals the end of a tag
    else if (value == 3) {
      // process the tag we just read
      processTag();
      // reset reading state
      counter = -1;
      break;
    }
    // if we are in the middle of reading a tag
    else if (counter >= 0) {
      // save valuee
      readData[counter] = value;
       
      // increment counter
      ++counter;
    }
  }
  digitalWrite(33,LOW);
  return tagId_dec;
  break;

  case 2:
    while (Serial2.available() > 0) {
      digitalWrite(35,HIGH);
  // read the incoming byte:
     int value = Serial2.read();
  // a "2" signals the beginning of a tag
    if (value == 2) {
      counter = 0; // start reading
    } 
    // a "3" signals the end of a tag
    else if (value == 3) {
      // process the tag we just read
      processTag();
      // reset reading state
      counter = -1;
      break;
    }
    // if we are in the middle of reading a tag
    else if (counter >= 0) {
      // save valuee
      readData[counter] = value;
       
      // increment counter
      ++counter;
    }
  }
  digitalWrite(35,LOW);
  return tagId_dec;
  break;  

  case 3:
    while (Serial3.available() > 0) {
      digitalWrite(37,HIGH);
  // read the incoming byte:
     int value = Serial3.read();
  // a "2" signals the beginning of a tag
    if (value == 2) {
      counter = 0; // start reading
    } 
    // a "3" signals the end of a tag
    else if (value == 3) {
      // process the tag we just read
      processTag();    
      // reset reading state
      counter = -1;
      break;
    }
    // if we are in the middle of reading a tag
    else if (counter >= 0) {
      // save valuee
      readData[counter] = value;
       
      // increment counter
      ++counter;
    }
  }
  digitalWrite(37,LOW);
  return tagId_dec;
  break;
  }
  
}
void loop() {
  //Serial 0
  if(Serial.available()>0){
    digitalWrite(31,LOW);
    delay(200);
    digitalWrite(31,HIGH);
    delay(200);
    digitalWrite(31,LOW);
 long ID = readTag(0);
 Serial.print("Guide 1: ");
 Serial.println(ID);
  if(checkTag(0)==1){
  digitalWrite(2,HIGH);
  delay(50);
  }
  }
  else{
  digitalWrite(2,LOW);
  }
  
  //Serial 1
  if(Serial1.available()>0){
    digitalWrite(33,LOW);
    delay(200);
    digitalWrite(33,HIGH);
    delay(200);
    digitalWrite(33,LOW);
 long ID = readTag(1);
 Serial.print("Guide 2: ");
 Serial.println(ID);
  if(checkTag(1)==1){
  digitalWrite(3,HIGH);
   delay(50);
  }
  }
  else{
  digitalWrite(3,LOW);
  }
  
  //Serial 2
  if(Serial2.available()>0){
    digitalWrite(35,LOW);
    delay(200);
    digitalWrite(35,HIGH);
    delay(200);
    digitalWrite(35,LOW);
 long ID = readTag(2);
 Serial.print("Guide 3: ");
 Serial.println(ID);
  if(checkTag(2)==1){
  digitalWrite(4,HIGH);
   delay(50);
  }
  }
  else{
  digitalWrite(4,LOW);
  }
  
  //Serial 3
  if(Serial3.available()>0){
    digitalWrite(37,LOW);
    delay(200);
    digitalWrite(37,HIGH);
    delay(200);
    digitalWrite(37,LOW);
 long ID = readTag(3);
 Serial.print("Guide 4: ");
 Serial.println(ID);
  if(checkTag(3)==1){
  digitalWrite(5,HIGH);
   delay(50);
  }
  }
  else{
  digitalWrite(5,LOW);
  }

  if(digitalRead(9)==1){
    while(1){
    digitalWrite(31,HIGH);
    digitalWrite(33,HIGH);
    digitalWrite(35,HIGH);
    digitalWrite(37,HIGH);
    }
  }

}
