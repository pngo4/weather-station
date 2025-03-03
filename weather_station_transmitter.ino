#include <WiFiConfig.h>

uint8_t receiverAddress[] = {0x34, 0xB7, 0xDA, 0xF6, 0x3C, 0xF4};

WeatherReport report;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  wifi_setup();

  peer_setup(receiverAddress);

}

void loop() {
  // put your main code here, to run repeatedly:
  report.temperature = 15; 
  report.humidity = 60;
  report.light = 55;

  send_report(receiverAddress, report);
  delay(500); 

}
