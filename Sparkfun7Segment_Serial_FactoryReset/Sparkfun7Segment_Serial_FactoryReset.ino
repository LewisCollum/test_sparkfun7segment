/* 
   Circuit:
   Arduino -------------- Serial 7-Segment
     5V   --------------------  VCC
     GND  --------------------  GND
      8   --------------------  RX
*/
#include <SoftwareSerial.h>

// These are the Arduino pins required to create a software seiral
//  instance. We'll actually only use the TX pin.
const int softwareTx = 8;
const int softwareRx = 7;

SoftwareSerial s7s(softwareRx, softwareTx);

unsigned int counter = 0;  // This variable will count up to 65k
char tempString[10];  // Will be used with sprintf to create strings

void setup()
{
  // Must begin s7s software serial at the correct baud rate.
  //  The default of the s7s is 9600.
  s7s.begin(9600);

  // Clear the display, and then turn on all segments and decimals
  clearDisplay();  // Clears display, resets cursor
  s7s.print(" HI ");  // Displays -HI- on all digits
  //setDecimals(0b111111);  // Turn on all decimals, colon, apos

  // Flash brightness values at the beginning
  setBrightness(0);  // Lowest brightness
  delay(1500);
  setBrightness(127);  // Medium brightness
  delay(1500);
  setBrightness(255);  // High brightness
  delay(1500);

  // Clear the display before jumping into loop
  clearDisplay(); 

  long int baudRates[12] = {2400, 4800, 9600, 14400, 19200, 38400, 57600, 76800, 115200, 250000, 500000, 1000000};
  for (int i=0; i<12; i++) {
    s7s.begin(baudRates[i]);  // Set new baud rate
    delay(10);  // Arduino needs a moment to setup serial
    Serial.write(0x81);  // Send factory reset command
  }

  s7s.begin(9600);
  delay(10);  // Arduino needs a moment to setup serial
  s7s.write(0x76);  // Clear the display
  s7s.print("test");
}

void loop(){}

void clearDisplay() {
  s7s.write(0x76);  // Clear display command
}
