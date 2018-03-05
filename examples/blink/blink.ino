#include <ESP8266WiFi.h>
#include <ESPHue.h>

const char* ssid = "SSID";    // your network SSID (name)
const char* pass = "PASSWORD";    // your network password

//                 bridge ip    username
ESPHue h = ESPHue("BRIDGE_IP", "USERNAME");

void setup() {
  Serial.begin(115200);
  connectToWifi();
}

void loop() {
  h.HSB(2000, 255, 255); //configure hsb
  h.on(); //configure on
  h.set(1); //apply set hsb to lamp 1
  h.set(2); //apply set hsb to lamp 2

  delay(1000);

  h.off(); //configure off
  h.set(1); //apply set off to lamp 1
  h.set(2); //apply set off to lamp 2

  delay(1000);
}

void connectToWifi() {
  Serial.println();
  Serial.println();
  Serial.print(F("Attempting to connect to network: "));
  Serial.println( ssid );

  uint8_t timeout = 0;
  WiFi.begin( ssid, pass );
  while( WiFi.status() != WL_CONNECTED && timeout < 250) {
    delay(250);
    Serial.print('.');
    timeout++;
  }
  Serial.println();
  if( timeout >= 250 ) Serial.println(F("Failed to connect to Wifi!"));
  else Serial.println(F("Connected to wifi"));
}
