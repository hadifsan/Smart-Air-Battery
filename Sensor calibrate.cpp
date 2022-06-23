#include <ACS712.h>

ACS712 sensor(ACS712_05B, A0);

void setup() {
  Serial.begin(115200);
}

void loop() {
    float zero_point = sensor.calibrate();
  Serial.print("Zero point for this sensor is ");
  Serial.println(zero_point);
  }
