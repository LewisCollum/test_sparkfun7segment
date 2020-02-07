/*
   Arduino -------------- Serial 7-Segment
     5V   --------------------  VCC
     GND  --------------------  GND
     SDA  --------------------  SDA (A4 on older 'duino's)
     SCL  --------------------  SCL (A5 on older 'duino's)
*/
#include <Wire.h> // Include the Arduino SPI library

const byte s7sAddress = 0x71;

void setup() {
  Wire.begin();

  for (int cycles = 0; cycles < 10; ++cycles) {
    Wire.beginTransmission(s7sAddress);
    for (int digit = 0; digit < 4; ++digit) {
      Wire.write(cycles);
    }
    Wire.endTransmission();
    delay(250);
  }
}

void loop() {}
