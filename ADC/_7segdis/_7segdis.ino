int num0[] = {0,0,0,0,0,0,1};
int num1[] = {1,0,0,1,1,1,1};
int num2[] = {0,0,1,0,0,1,0};
int num3[] = {0,0,0,0,1,1,0};
int num4[] = {1,0,0,1,1,0,0};
int num5[] = {0,1,0,0,1,0,0};
int num6[] = {0,1,0,0,0,0,0};
int num7[] = {0,0,0,1,1,1,1};
int num8[] = {0,0,0,0,0,0,0};
int num9[] = {0,0,0,0,1,0,0};


void setup() {
  // put your setup code here, to run once:
for(int i=2;i<=8;i++){
  pinMode(i, OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=2;i<=8;i++){
  digitalWrite(i, num4[i-2]);
}

}
