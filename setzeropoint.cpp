#include <ACS712.h>

/*
  This example shows how to set zero point of your sensor
*/

// We have 30 amps version sensor connected to A1 pin of arduino
// Replace with your version if necessary
ACS712 sensor(ACS712_05B, A0);

void setup() {
  Serial.begin(115200);

  // Value obtained using sensor.calibrate() when no current flows through the sensor
   sensor.calibrate();
  sensor.setZeroPoint(841);
}

void loop() {
  
    // Get current from sensor
  float I = sensor.getCurrentDC();
  
  // Send it to serial
  Serial.println(String("I = ") + I + " A");
  
  // Wait one second before the new cycle
  delay(1000);
  }
