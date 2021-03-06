#include <SD.h> //SD Card Library
#include <Wire.h> //I2C Library

//SPI SD Card Pins
  //MOSI = Pin 11
  //MISO = Pin 12
  //SCLK = PIN 13

int CS_pin = 10;
int pow_pin = 8;

//I2C Temperature Pins
  //SDA = Analog Pin 4
  //SCL = Analog Pin 5

//IR Distance Sensor Pins
int IR1_pin = 2;
int IR2_pin = 3;

//Light Sensor Pins
int light_pin = 1;

float refresh_rate = 0.0; //Datalogger Refresh Rate
int temp_address = 72; //Address of the I2C Temp Sensor
long id = 1; //Use this to store the id # of our reading

void setup() {
  Wire.begin();
  Serial.println(9600);
  Serial.println("Initialiing Card");
  //CS Pin is an output
  pinMode(CS_pin,OUTPUT);

  //SD Card will Draw power from Pin 8, so set it high
  pinMode(pow_pin,OUTPUT);
  digitalWrite(pow_pin,HIGH);

  //Initialize Card
  if(!SD.begin(CS_pin))
  {
    Serial.println("Card Failure");
    return;
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

  //Write Log File Header
  File logFile = SD.open("LOG.csv",FILE_WRITE);
  if(logFile)
  {
    logFile.println(", , , ,"); //Just a leading blank line, incase there was previous data
    String header = "ID, Light, Temp, IR1, IR2";
    logFile.println(header);
    logFile.close();
    Serial.println(header);  
  }
  else
  {
    Serial.println("Couldn't open log file");
  }
}

void loop()
{
  //Check Light Level
  int light_level = analogRead(light_pin);
  
  //Read Temperature
  Wire.beginTransmission(temp_address); //Start talking
  Wire.send(0); //Ask for Register zero
  Wire.endTransmission(); //Complete Transmission
  Wire.requestFrom(temp_address, 1); //Request 1 Byte
  while(Wire.available() == 0); //wait for response
  int temp_c = Wire.receive(); // Get the temp
  int temp_f = round(temp_c*9.0/5.0 +32.0);  //Convert to stupid American units
  
  //Read Distances from Infrared Distance sensors 
  int IR1_val = analogRead(IR1_pin);
  int IR2_val = analogRead(IR2_pin);
  
  //Create Data string for storing to SD card
  //We will use CSV Format  
  String dataString = String(id) + ", " + String(light_level) + ", " + String(temp_f) + ", " + String(IR1_val) + ", " + String(IR2_val); 
  
  //Open a file to write to
  //Only one file can be open at a time
  File logFile = SD.open("LOG.csv", FILE_WRITE);
  if (logFile)
  {
    logFile.println(dataString);
    logFile.close();
    Serial.println(dataString);
  }
  else
  {
    Serial.println("Couldn't open log file");
  }
  
  //Increment ID number
  id++;
  
  delay(refresh_rate);
}
