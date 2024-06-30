// https://github.com/RobTillaart/MCP_DAC
#include "MCP_DAC.h" // v0.5.1
#define CS 10
#define CH 0
#define OFFSET 0.1

MCP4911 MCP;  // Hardware SPI

void setup() {
  Serial.begin(115200);
  SPI.begin();
  MCP.begin(CS); // chip select
  delay(500);
  uint16_t val = computeVoltValue(2.0 + OFFSET);
  MCP.write(val, CH);
}

void loop() {
}

uint16_t computeVoltValue(float volt) {
  return (uint16_t)( volt / (5.0 / 1023) );
}
