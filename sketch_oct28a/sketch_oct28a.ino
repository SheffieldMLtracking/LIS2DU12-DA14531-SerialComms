#include <Wire.h>

const int DEVICE_ADDRESS = 0x18; // Replace with your device's I2C address
const int WHO_AM_I_REGISTER = 0x58; // Replace with the correct register

void setup() {
  Wire.begin();
  Serial.begin(9600);

  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(WHO_AM_I_REGISTER);
  Wire.endTransmission(false); // Send repeated start

  Wire.requestFrom(DEVICE_ADDRESS, 1); // Request 1 byte
  if (Wire.available()) {
    uint8_t whoAmI = Wire.read();
    Serial.print("WHO_AM_I = 0x");
    Serial.println(whoAmI, HEX);
  } else {
    Serial.println("Failed to read WHO_AM_I register");
  }
}

void loop() {
  // Nothing here
}
