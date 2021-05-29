#include <Servo.h>

int pos = 0;
int sensorValue = 0;

Servo servo_9;

void setup()
{
  servo_9.attach(9, 500, 2500);
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop()
{
  
  sensorValue = analogRead(A0);
  sensorValue = map(sensorValue,0,1023,0,180);
  Serial.println(sensorValue);
  
  servo_9.write(sensorValue);
}