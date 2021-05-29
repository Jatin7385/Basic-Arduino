void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2,INPUT);
}

void loop()
{
  if(digitalRead(2)==HIGH)
  {
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
  }
}