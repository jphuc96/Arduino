int a = 0;
int b = 1;
int c = 2;
int d = 3;
int e = 4;
int f = 5;
int g = 6;
int n1 = 7;
int n2 = 8;
int carRed1 = 9; // assign the car1 lights
int carYellow1 = 10;
int carGreen1 = 11;
int carRed2 = 12; // assign the car2 lights
int carYellow2 = 13;
int carGreen2 = A5;
int pedRed1 = A4; // assign the pedestrian1 lights
int pedGreen1 = A3;
int pedRed2 = A2; // assign the pedestrian2 lights
int pedGreen2 = A1;
int crossTime = 3000; // time allowed to cross
int so(int a1)
{
  if (a1 == 0)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  if (a1 == 1)
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (a1 == 2)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (a1 == 3)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (a1 == 4)
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (a1 == 5)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (a1 == 6)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (a1 == 7)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (a1 == 8)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (a1 == 9)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
}


int i;
int j;
int t;
int T=1000;
void chay(int d1,int d2) {
  if(d1<9)
  for (j = d1/10; j >= d2/10; j--)
  {
    for (i =  (d1 - (d1 / 10) * 10); i >= 0; i--)
    {
      for (t = 0; t < T/10; t++)
      {
        digitalWrite(n1, LOW);
        digitalWrite(n2, HIGH);
        so(i);
        delay(5);

        digitalWrite(n1, HIGH);
        digitalWrite(n2, LOW);
        so(j);
        delay(5);
      }
      if (j == d2 / 10 && i == d2 - (d2 / 10) * 10)
        break;
    }
    if (j == d2 / 10 && i == d2 - (d2 / 10) * 10)
      break;
   }
  else
  for (j = d1/10; j >= d2/10; j--)
  {
    if(j==d2/10)
      for (i = 9; i >= 0; i--)
      {
       for (t = 0; t < T/10; t++)
       {
        digitalWrite(n1, LOW);
        digitalWrite(n2, HIGH);
        so(i);
        delay(5);

        digitalWrite(n1, HIGH);
        digitalWrite(n2, LOW);
        so(j);
        delay(5);
       }
        if (j == d2 / 10 && i == d2 - (d2 / 10) * 10)
        break;
    }
    if (j == d2 / 10 && i == d2 - (d2 / 10) * 10)
      break;
    else
    for (i =  (d1 - (d1 / 10) * 10); i >= 0; i--)
    {
      for (t = 0; t < T/10; t++)
      {
        digitalWrite(n1, LOW);
        digitalWrite(n2, HIGH);
        so(i);
        delay(5);

        digitalWrite(n1, HIGH);
        digitalWrite(n2, LOW);
        so(j);
        delay(5);
      }
      if (j == d2 / 10 && i == d2 - (d2 / 10) * 10)
        break;
    }
    if (j == d2 / 10 && i == d2 - (d2 / 10) * 10)
      break;
    }  
}




void setup()
{
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(carRed1, OUTPUT);
  pinMode(carYellow1, OUTPUT);
  pinMode(carGreen1, OUTPUT);
  pinMode(pedRed1, OUTPUT);
  pinMode(pedGreen1, OUTPUT);
  pinMode(carRed2, OUTPUT);
  pinMode(carYellow2, OUTPUT);
  pinMode(carGreen2, OUTPUT);
  pinMode(pedRed2, OUTPUT);
  pinMode(pedGreen2, OUTPUT);

}
void loop() 
{

digitalWrite(pedRed1, LOW); // ped red 2 on
digitalWrite(carYellow1, LOW); // car yellow 2 off
digitalWrite(carRed1, HIGH); // car red 2 on
digitalWrite(pedGreen1, HIGH); //ped green 2 off
digitalWrite(pedRed2, HIGH); //ped red 1 off
digitalWrite(carRed2, LOW); //car red 1 off
digitalWrite(pedGreen2, LOW); // ped green 1 on
digitalWrite(carGreen2, HIGH); //car green 1 on
chay(18,0);

digitalWrite(carGreen2, LOW); // car green 1 off
digitalWrite(carYellow2, HIGH); // car yellow 1 on






digitalWrite(pedRed2, LOW); // ped red 1 on
digitalWrite(carYellow2, LOW); // car yellow 1 off
digitalWrite(carRed2, HIGH); // car red 1 on
digitalWrite(pedRed1, HIGH); // ped red 2 off
digitalWrite(carRed1, LOW); // car red 2 off
digitalWrite(pedGreen1, LOW); // ped green 2 on
digitalWrite(carGreen1, HIGH); // car green 2 on
digitalWrite(pedGreen2,HIGH);
chay(15,0); // wait for preset time period

digitalWrite(carGreen1, LOW); // car green 2 off
digitalWrite(carYellow1, HIGH); // car yellow 2 on
chay(3,0);




}


