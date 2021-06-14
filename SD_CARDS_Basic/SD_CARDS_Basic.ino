//Code from Jeremy Blums tutorial Series
#include <SD.h>

//SPI settings
//MOSI,MISO,SCLK Set by default

int CS_pin = 10; //Chip Select Pin
int pow_pin = 8;

float refresh_rate = 0.0;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing Card");
  //CS Pin is an output
  pinMode(CS_pin,OUTPUT);

  //Card will draw power from pin 8, so set it high.
  pinMode(pow_pin,OUTPUT);
  digitalWrite(pow_pin,HIGH);

  //Check if card ready
  if(!SD.begin(CS_pin))
  {
    Serial.println("Card Failed");
    return; //Ends the program
  }
  Serial.println("Card Ready");

  //Read the configuration information (Commands.txt)
  File commandFile = SD.open("COMMANDS.txt"); //In the read mode
  if(commandFile)
  {
    Serial.println("Reading Command File");

    float decade = pow(10,commandFile.available() - 1); //Decade is the size of the number in decades of 10
    //So the decade of 1000 will be 1000, decade of 500 will be 100 so on so forth 
    //So if the number is 5000, commandFile.available() should return 4(no. of digits), and 4-1=3, 10^3 = 1000. Therefore the decade of 5000 is 1000

    //Gets back the number for us
    while(commandFile.available())
    {
      float temp = (commandFile.read()-'0');
      refresh_rate = temp*decade + refresh_rate;
      decade = decade/10;
    }
    Serial.print("Refresh Rate = ");
    Serial.println(refresh_rate);
    Serial.println("ms");
  }
  else
  {
    Serial.println("Could not read command file");
  }
}

void loop() {
  String dataString = "Data String";

  //Open a file to write to
  //Only one file can be open at a time
  File dataFile = SD.open("log.txt",FILE_WRITE);
  if(dataFile)
  {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println("dataString");
  }
  else
  {
    Serial.println("Couldn't access file");
  }
  delay(refresh_rate);
}
