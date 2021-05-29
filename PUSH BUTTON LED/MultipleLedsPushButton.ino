void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,INPUT);
}

void loop()
{
  if(digitalRead(10)==HIGH){
  	digitalWrite(13,HIGH);
    delay(3000);
    digitalWrite(13,LOW);
    delay(1000);
    digitalWrite(12,HIGH);
    delay(3000);
    digitalWrite(12,LOW);
    delay(1000);
    digitalWrite(11,HIGH);
    delay(3000);
    digitalWrite(11,LOW);
    delay(1000);
  }
}