int baselineTemp = 0;
int celsius = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(A0, INPUT);
}

void loop()
{
  baselineTemp = 40;
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  Serial.println(analogRead(A0));
  
  if (celsius < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
  }
  if (celsius >= baselineTemp && celsius < baselineTemp + 10) {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
  }
  if (celsius >= baselineTemp + 10 && celsius < baselineTemp + 20) {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(7, LOW);
  }
  if (celsius >= baselineTemp + 20 && celsius < baselineTemp + 30) {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
  }
  if (celsius >= baselineTemp + 30) {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
  }
  delay(1000); // Wait for 1000 millisecond(s)
}