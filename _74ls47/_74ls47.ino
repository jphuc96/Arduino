int digit = 0;

void quetled(){

if( digit = 0 ){
digitalWrite(0, 0);
digitalWrite(1, 0);
digitalWrite(2, 0);
digitalWrite(3, 0);

digitalWrite(4, 0);
digitalWrite(5, 0);
digitalWrite(6, 0);
digitalWrite(7, 0);
}

if( digit = 1 ){
digitalWrite(0, 1);
digitalWrite(1, 0);
digitalWrite(2, 0);
digitalWrite(3, 0);

digitalWrite(4, 1);
digitalWrite(5, 0);
digitalWrite(6, 0);
digitalWrite(7, 0);
}

if( digit = 2 ){
digitalWrite(0, 0);
digitalWrite(1, 1);
digitalWrite(2, 0);
digitalWrite(3, 0);

digitalWrite(4, 0);
digitalWrite(5, 1);
digitalWrite(6, 0);
digitalWrite(7, 0);
}

if( digit = 3 ){
digitalWrite(0, 1);
digitalWrite(1, 1);
digitalWrite(2, 0);
digitalWrite(3, 0);

digitalWrite(4, 1);
digitalWrite(5, 1);
digitalWrite(6, 0);
digitalWrite(7, 0);
}

if( digit = 4 ){
digitalWrite(0, 0);
digitalWrite(1, 0);
digitalWrite(2, 1);
digitalWrite(3, 0);

digitalWrite(4, 0);
digitalWrite(5, 0);
digitalWrite(6, 1);
digitalWrite(7, 0);
}

if( digit = 5 ){
digitalWrite(0, 1);
digitalWrite(1, 0);
digitalWrite(2, 1);
digitalWrite(3, 0);

digitalWrite(4, 1);
digitalWrite(5, 0);
digitalWrite(6, 1);
digitalWrite(7, 0);
}

if( digit = 6 ){
digitalWrite(0, 0);
digitalWrite(1, 1);
digitalWrite(2, 1);
digitalWrite(3, 0);

digitalWrite(4, 0);
digitalWrite(5, 1);
digitalWrite(6, 1);
digitalWrite(7, 0);
}

if( digit = 7 ){
digitalWrite(0, 1);
digitalWrite(1, 1);
digitalWrite(2, 1);
digitalWrite(3, 0);

digitalWrite(4, 1);
digitalWrite(5, 1);
digitalWrite(6, 1);
digitalWrite(7, 0);
}

if( digit = 8 ){
digitalWrite(0, 0);
digitalWrite(1, 0);
digitalWrite(2, 0);
digitalWrite(3, 1);

digitalWrite(4, 0);
digitalWrite(5, 0);
digitalWrite(6, 0);
digitalWrite(7, 1);
}

if( digit = 9 ){
digitalWrite(0, 1);
digitalWrite(1, 0);
digitalWrite(2, 0);
digitalWrite(3, 1);

digitalWrite(4, 1);
digitalWrite(5, 0);
digitalWrite(6, 0);
digitalWrite(7, 1);
}
}

void setup() {
  // put your setup code here, to run once:
for(int i=2;i<=13;i++){
  pinMode(i, OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
  
//digit1a
  digit = 1;
quetled();
digitalWrite(8, 1);
digitalWrite(9, 0);


//digit1b

digitalWrite(8, 0);
digitalWrite(9, 1);
delay(5);

}
