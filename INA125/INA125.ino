
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int mV_in = 2000;
  
  analogWrite(9,mV_in*255/(5*1000));
  
int ADC_val=analogRead(A0);
Serial.print("Voltage_in: ");
Serial.print(mV_in);
Serial.print("        ");

Serial.print("Voltage_out: ");
Serial.println((float)ADC_val*5/1024);
}
