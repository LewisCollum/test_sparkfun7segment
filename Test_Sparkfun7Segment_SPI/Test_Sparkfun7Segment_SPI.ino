/*
 Pin 10 on Uno (CS) to CS on OpenSegment
 Pin 11 to MOSI
 Pin 12 to MISO
 Pin 13 to SCK
*/

#include <SPI.h>

int csPin = 10; //You can use any IO pin but for this example we use 10

int cycles = 0;

void setup() 
{
  pinMode(csPin, OUTPUT);
  digitalWrite(csPin, HIGH); //By default, don't be selecting OpenSegment
  
  SPI.begin(); //Start the SPI hardware
  SPI.setClockDivider(SPI_CLOCK_DIV64); //Slow down the master a bit

  //Send the reset command to the display - this forces the cursor to return to the beginning of the display
  digitalWrite(csPin, LOW); //Drive the CS pin low to select OpenSegment
  SPI.transfer('v'); //Reset command

  for (int cycles = 0; cycles < 10; ++cycles) {
    for (int digit = 0; digit < 4; ++digit) {
      SPI.transfer(cycles);
    }
    delay(250);
  }

  SPI.endTransaction();
}

void loop() {}
