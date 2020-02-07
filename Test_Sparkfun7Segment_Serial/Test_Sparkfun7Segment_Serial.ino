/* 
   Circuit:
   Arduino -------------- Serial 7-Segment
     5V   --------------------  VCC
     GND  --------------------  GND
      8   --------------------  RX
*/
#include <SoftwareSerial.h>

const int softwareTx = 8;
const int softwareRx = 7;

SoftwareSerial s7s(softwareRx, softwareTx);

unsigned int counter = 0; 
char tempString[10];  // Will be used with sprintf to create strings

void setup() {
  s7s.begin(9600);

  for (int cycles = 0; cycles < 10; ++cycles) {
    for (int digit = 0; digit < 4; ++digit) {
      s7s.write(cycles);
    }
    delay(250);
  }
}

void loop(){}
