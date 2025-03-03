#include <WiFiConfig.h>
#include <LiquidCrystal_I2C.h>

// Initialize a WeatherReport to store the values
WeatherReport report;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  // Put ESP32 in WiFi mode
  wifi_setup();
  // Configure this ESP32 to receive WeatherReports
  set_report_receiver(&report);

  //initialize display
  lcd.init();
  lcd.backlight();
}

void loop() {
  Serial.print("TEMP: ");
  Serial.println(report.temperature);
  Serial.print("HUM: ");
  Serial.println(report.humidity);
  Serial.print("LIGHT: ");
  Serial.println(report.light);

  //LCD display
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(report.temperature);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Hum:");
  lcd.print(report.humidity);
  lcd.print("%, ");
  if(report.light > 100) 
  {
    lcd.print("Day");
  } else
  {
    lcd.print("Night");
  }
  


  delay(10000);
}
