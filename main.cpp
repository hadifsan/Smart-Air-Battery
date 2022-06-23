#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ACS712.h>

ACS712 sensor(ACS712_05B, A0);

// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "aoJVOXlKNpWOMJTttrZbN_MkF0l8W2_w";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "mohdrohani9766@unifi";
char pass[] = "0132069766";

void setup()
{
  // Debug console
  Serial.begin(9600);
  // Value obtained using sensor.calibrate() when no current flows through the sensor
  sensor.calibrate();
  sensor.setZeroPoint(841);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  lcd.begin();  
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Welcome to");
  lcd.setCursor(0,1);
  lcd.print("Air Battery");  
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Connecting:");
  lcd.setCursor(11,0);
  lcd.print(ssid);
  WiFi.begin(ssid, password);

  while (ESP8266WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    lcd.setCursor(0,1);
    lcd.print(".........");
    delay(500);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Wifi Connected!");
  delay(500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IP ADDRESS:");
  lcd.setCursor(0, 1);
  lcd.print(ESP8266WiFi.localIP());
  
}

void loop()
{
  Blynk.run();
    // Get current from sensor
  float I = sensor.getCurrentDC();
  
  // Send it to serial
  Serial.println(String("I = ") + I + " A");
  
  // Wait one second before the new cycle
  delay(1000);

  Blynk.virtualWrite(V5, I);
delay(1000);
}
