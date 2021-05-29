int red = 0;
int blue = 0;
int green = 0;
void setup()
{
  pinMode(11, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
}

void loop()
{
  red = map(analogRead(A0),0,1023,0,255);
  blue = map(analogRead(A1),0,1023,0,255);
  green = map(analogRead(A2),0,1023,0,255);
  
  analogWrite(11,red);
  analogWrite(10,blue);
  analogWrite(9,green);
  
}