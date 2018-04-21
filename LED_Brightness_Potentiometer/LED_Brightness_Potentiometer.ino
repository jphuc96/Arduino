void setup() {

pinMode(A0,INPUT);
pinMode(9,OUTPUT);

Serial.begin(9600);
}

void loop() {

int input = analogRead(A0);     //read voltage at pin A0
int output = map(input,0,1023,0,255);     //convert 0-1023 into 0-255 scale
int percent = map(input,0,1023,0,100);    //convert 0-1023 into 0-100 scale

//Print out Serial Monitor the percentage of the brightness
Serial.print("Brightness: ");
Serial.print(percent);
Serial.print("%");
Serial.println();

//write the voltage to pin A0 to control LED
analogWrite(9,output);


}
