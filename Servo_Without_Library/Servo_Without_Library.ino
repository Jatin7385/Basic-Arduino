int servoPin = 7;
int d = 500; 
void setup() {
   pinMode(servoPin,OUTPUT);
}

//Works almost perfectly but... after 180 deg, when it is supposed to come back to 0, it behaves in a weird fashion.
//DelayMicroseconds = 2450 ==>180 position
//DelayMicroseconds = 500 ==>0 position
//DelayMicroseconds = 1450 ==>90 position
void loop() {
 
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(d);
  digitalWrite(servoPin,LOW);
  delay(150);
  d+=50;
  if(d>=2450){d = 500;}

}
