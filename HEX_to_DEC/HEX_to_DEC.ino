String hexstring = "0000B4A05B";
long decnumber = strtol(hexstring.c_str(), NULL, 16);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.print(decnumber);
}

void loop() {
  // put your main code here, to run repeatedly:

}
