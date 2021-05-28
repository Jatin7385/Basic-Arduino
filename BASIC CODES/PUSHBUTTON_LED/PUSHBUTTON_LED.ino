void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(2,INPUT);
}

void loop()
{
  //Serial.println("Yes");
  if(digitalRead(2)==HIGH)
  {
    Serial.println("Yes");
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
  }
}
