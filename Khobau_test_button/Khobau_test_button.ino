void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(10,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int v1 = digitalRead(4);
int v2 = digitalRead(5);
int v3 = digitalRead(6);
int v4 = digitalRead(7);
int v5 = digitalRead(8);
int v6 = digitalRead(9);
int v7 = digitalRead(10);

Serial.print(v1);
Serial.print("    ");
Serial.print(v2);
Serial.print("    ");
Serial.print(v3);
Serial.print("    ");
Serial.print(v4);
Serial.print("    ");
Serial.print(v5);
Serial.print("    ");
Serial.print(v6);
Serial.print("    ");
Serial.print(v7);
Serial.print("    ");
Serial.println();
}
