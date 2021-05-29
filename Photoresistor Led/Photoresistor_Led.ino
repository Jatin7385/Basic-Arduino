int sensorReading=0;
int ledBrightness = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(A0,INPUT);
}

void loop()
{
  sensorReading = analogRead(A0);
  ledBrightness = map(sensorReading,0,1023,0,255);
  analogWrite(11,ledBrightness);
  Serial.print(sensorReading);
  Serial.print(",");
  Serial.println(ledBrightness);
}