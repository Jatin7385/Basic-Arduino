int potentiometerValue = 0;
int ledBrightness = 0;
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(8,INPUT);
  pinMode(A0,INPUT);
}

void loop()
{
  potentiometerValue = analogRead(A0);
  ledBrightness = map(potentiometerValue,0,1023,0,255);
  analogWrite(9,ledBrightness);}