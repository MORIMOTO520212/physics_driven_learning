// Reference: https://github.com/adafruit/Adafruit_ADS1X15/blob/master/examples/singleended/singleended.ino

#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
//Adafruit_ADS1015 ads;     /* Use this for the 12-bit version */

int16_t adc0, adc1, adc2, adc3;
float volts0, volts1, volts2, volts3;

void setup() {
  Serial.begin(9600);

  if (!ads.begin()) {
    Serial.println("ADSの初期化に失敗しました。");
    while (1);
  }
}

void loop() {
  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);

  volts0 = ads.computeVolts(adc0);
  volts1 = ads.computeVolts(adc1);
  volts2 = ads.computeVolts(adc2);
  volts3 = ads.computeVolts(adc3);


  Serial.print("IN1-:"); Serial.print(volts0); Serial.print(", IN1+:"); Serial.print(volts1); Serial.print(", OUT1:"); Serial.print(volts2);
  Serial.println("");
  delay(300);
}
