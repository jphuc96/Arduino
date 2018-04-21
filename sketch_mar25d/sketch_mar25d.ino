int led1 = 5;
int led2 = 3;
int brightness = 0;
int fadeAmount = 5;
void setup() {
  // put your setup code here, to run once:
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(led1, brightness);
analogWrite(led2, brightness);

brightness = brightness + fadeAmount;

if (brightness == 0 || brightness == 255)
{fadeAmount = -fadeAmount;}

delay(30);
}
