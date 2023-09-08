#include "ZMPT101B.h"
ZMPT101B voltageSensor(34);
float dcOffsetSamples = 0;

float analogBuffer[400];

float ADCScale = 4095.0;
float Vref = 5.0;
float sensitivity = 0.00527;

void setup() {
  // put your setup code here, to run once:
  delay (1000);
  Serial.begin (115200);
  pinMode (34, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 //Serial.println ("Removing DC Offset...");
 // delay (100);

  float accum = 0;

  for (int i=0; i<400; i++)
  {
    accum += analogRead (34);
    delayMicroseconds(250);
  }

  dcOffsetSamples = accum/400;
  voltageSensor.setZeroPoint(dcOffsetSamples);
  voltageSensor.setSensitivity (sensitivity);
  //float dcOffsetVolts = dcOffsetSamples * Vref/ADCScale;
  //Serial.println (dcOffsetVolts);
  //Serial.print (String(dcOffsetSamples) + "     ");
  float vrms = voltageSensor.getVoltageAC(50);

  Serial.println (vrms*0.37);
  delay(1000);
  

}
