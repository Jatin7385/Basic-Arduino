#include <SPI.h>

//Set the Slave Select Pin
//Other SPI Pins are set automatically
int SS=10;

void setup() {
  //Set SS Pin Directions
  //Others are Handled Automatically
  pinMode(SS,OUTPUT);

  //Initialize SPI
  SPI.begin();
}
//A function to set the LED to a certain level
void setLed(int reg, int level)
{
  digitalWrite(SS,LOW); //LOW on SPI means that we are trying to select that pin
  SPI.transfer(reg);
  SPI.transfer(level);
  digitalWrite(SS,HIGH);
} 
void loop() {
  for(int i=0;i<=2;i++)
  {
    for(int j=50;j<=255;j++)
    {
      setLed(i,j);
      delay(20);
    }
    delay(500);
    for(int j=255;j>=50;j--)
    {
      setLed(i,j);
      delay(20);
    }
  }

}
