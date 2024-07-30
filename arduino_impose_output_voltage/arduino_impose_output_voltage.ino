// Reference:
// MCP_DAC Library https://github.com/RobTillaart/MCP_DAC
// ADS1X15 Library https://github.com/adafruit/Adafruit_ADS1X15/blob/master/examples/singleended/singleended.ino
#include <Adafruit_ADS1X15.h>
#include "MCP_DAC.h" // v0.5.1

#define CS 10      // MCP_DAC Chip Select Pin
#define CH 0       // MCP_DAC Channel
#define OFFSET 0.02 // Voltage Loss Offset
#define LR 0.5     // Learning Rate

Adafruit_ADS1115 ads;
MCP4911 MCP;

void setup() {
  Serial.begin(115200);
  // setup MCP
  SPI.begin();
  MCP.begin(CS); // chip select
  // setup ADS1X15
  if (!ads.begin()) {
    Serial.println("ADS initialization failed.");
    while (1);
  }
  delay(500);
}

void loop() {
  // clampedVolt(800, 3.75); // desired: 3.75v
  // clampedVolt(800, 2.50); // desired: 2.50v
  // clampedVolt(800, 1.00); // desired: 1.00v
  // clampedVolt(800, 2.25); // desired: 2.25v
  clampedVolt(800, 2.25);
  delay(1000); // wait 1sec
}

void clampedVolt(int steps, float desiredVolt) {
  for(int i = 0; i < steps; i++) {
    int16_t adcCode = ads.readADC_SingleEnded(0);
    float freeVolt = ads.computeVolts(adcCode);
    float clampedVolt = computeClampedVolt(desiredVolt, freeVolt);
    // float clampedVolt = 3.00;
    uint16_t clampedCode = computeAdcValue(clampedVolt);
    MCP.write(clampedCode, CH);
    Serial.print("desired: "); Serial.print(desiredVolt); Serial.print(", freeVolt:"); Serial.print(freeVolt); 
    Serial.print(", clampedVolt: "); Serial.println(clampedVolt);
    delay(10);
  }
}

uint16_t computeAdcValue(float volt) {
  return (uint16_t)( (volt + OFFSET) / (5.0 / 1023) );
}

float computeClampedVolt(float desiredVolt, float freeVolt) {
  return LR * desiredVolt + (1 - LR) * freeVolt;
}