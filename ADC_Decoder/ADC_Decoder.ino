// parameters:
int a=5,b=4,c=3,d=2; //BCD data
int n1=8,n2=9,n3=10,n4=11,n5=12,n6=13; //common pins
int dp=7; //decimal point
int i;
int data[6];  //array combined
int num1[3];  //array of first number
int num2[3];  //array of second number
int value1,value2; //data input
int val1[10],val2[10];
int timedelay=3000; //microsecond
int interval;
// function prototype:
void bcd(int x);        //send BCD code to BCD decoder 74LS47
void data_out(int y);   //send data array to 7 segment LED
int maximum(int x[],int s);
void setup() {
 // data pins setup
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(dp,OUTPUT);
  //common pins setup
pinMode(n1,OUTPUT);
pinMode(n2,OUTPUT);
pinMode(n3,OUTPUT);
pinMode(n4,OUTPUT);
pinMode(n5,OUTPUT);
pinMode(n6,OUTPUT);
}
void loop() {
//get input data:
interval = 600;
for(i=0;i<10;i++){
val1[i] = map(analogRead(A0),0,1015,0,300);
val2[i] = map(analogRead(A1),0,1015,0,300);
}
value1 = maximum(val1,10);
value2 = maximum(val2,10);

if(interval - millis()%(interval+1) == 0){
value1 = map(analogRead(A0),0,1015,0,300);
value2 = map(analogRead(A1),0,1015,0,300);
}

  //create num1 array, the result array of the number 'abc' will be num1[3]={a,b,c};
   if(value1>=100){
    num1[0] = int(value1/100);
    num1[1] = int((value1-100*num1[0])/10);
    num1[2] = value1 - 10*num1[1] - 100*num1[0];
 }
  else if(value1<100&&value1>=10){
    num1[0] = 0;
    num1[1] = int(value1/10);
    num1[2] = value1 - 10*num1[1];
  }
  else{
    num1[0] = 0;
    num1[1] = 0;
    num1[2] = value1;
  }

  //create num2 array, the result array of the number 'def' will be num1[3]={d,e,f}; 
  if(value2>=100){
    num2[0] = int(value2/100);
    num2[1] = int((value2-100*num2[0])/10);
    num2[2] = value2 - 10*num2[1] - 100*num2[0];
 }
  else if(value2<100&&value2>=10){
    num2[0] = 0;
    num2[1] = int(value2/10);
    num2[2] = value2 - 10*num2[1];
  }
  else{
    num2[0] = 0;
    num2[1] = 0;
    num2[2] = value2;
  }
    
  //combine the two array into one, the result array will be data[6]={a,b,c,d,e,f}
    for(i=0;i<3;i++){
      data[i]=num1[i];
    }
    for(i=3;i<6;i++){
      data[i]=num2[i-3];
    }
          
data_out(data); // send data array above into 7 segment LED
}
 //send BCD code to BCD decoder 74LS47
void bcd(int x){
  switch(x){
    case 0:
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    break;
    case 1:
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,1);
    break;
    case 2:
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,1);
    digitalWrite(d,0);
    break;
    case 3:
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,1);
    digitalWrite(d,1);
    break;
    case 4:
    digitalWrite(a,0);
    digitalWrite(b,1);
    digitalWrite(c,0);
    digitalWrite(d,0);
    break;
    case 5:
    digitalWrite(a,0);
    digitalWrite(b,1);
    digitalWrite(c,0);
    digitalWrite(d,1);
    break;
    case 6:
    digitalWrite(a,0);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,0);
    break;
    case 7:
    digitalWrite(a,0);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    break;
    case 8:
    digitalWrite(a,1);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    break;
    case 9:
    digitalWrite(a,1);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,1);
    break;
  }
}
//send data array into 7 segment LED
void data_out(int y[]){
  //digit 1
digitalWrite(n1,1);
digitalWrite(n2,0);
digitalWrite(n3,0);
digitalWrite(n4,0);
digitalWrite(n5,0);
digitalWrite(n6,0);
digitalWrite(dp,1);
    bcd(y[0]);
delayMicroseconds(timedelay);
  //digit 2
digitalWrite(n1,0);
digitalWrite(n2,1);
digitalWrite(n3,0);
digitalWrite(n4,0);
digitalWrite(n5,0);
digitalWrite(n6,0);
digitalWrite(dp,0);
    bcd(y[1]);
delayMicroseconds(timedelay);
  //digit 3
digitalWrite(n1,0);
digitalWrite(n2,0);
digitalWrite(n3,1);
digitalWrite(n4,0);
digitalWrite(n5,0);
digitalWrite(n6,0);
digitalWrite(dp,1);
    bcd(y[2]);
delayMicroseconds(timedelay);
  //digit 4
digitalWrite(n1,0);
digitalWrite(n2,0);
digitalWrite(n3,0);
digitalWrite(n4,1);
digitalWrite(n5,0);
digitalWrite(n6,0);
digitalWrite(dp,1);
    bcd(y[3]);
delayMicroseconds(timedelay);
  //digit 5
digitalWrite(n1,0);
digitalWrite(n2,0);
digitalWrite(n3,0);
digitalWrite(n4,0);
digitalWrite(n5,1);
digitalWrite(n6,0);
digitalWrite(dp,0);
    bcd(y[4]);
delayMicroseconds(timedelay);
  //digit 6
digitalWrite(n1,0);
digitalWrite(n2,0);
digitalWrite(n3,0);
digitalWrite(n4,0);
digitalWrite(n5,0);
digitalWrite(n6,1);
digitalWrite(dp,1);
    bcd(y[5]);
delayMicroseconds(timedelay);

}

int maximum(int x[],int s){
int m = x[0];
for(i=1;i<s;i++){
  if(x[i]>=m){
    m = x[i];
  }
}  
  return m;
}
