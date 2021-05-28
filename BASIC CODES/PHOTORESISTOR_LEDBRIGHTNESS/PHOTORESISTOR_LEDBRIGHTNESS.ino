int sensorReading=0;
int ledBrightness = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(A0,INPUT);
}

void loop()
{
  sensorReading = analogRead(A0);
  sensorReading = constrain(sensorReading,750,900);
  ledBrightness = map(sensorReading,750,900,255,0);
  analogWrite(10,ledBrightness);
  Serial.print(sensorReading);
  Serial.print(",");
  Serial.println(ledBrightness);
}
