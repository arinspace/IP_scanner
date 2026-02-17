#include <Arduino.h>
#include <Wire.h>

void setup() {
    Serial.begin(115200);
    delay(1000);

    Wire.begin(21, 22);

    Serial.println("Scanning...");

    for (byte address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        if (Wire.endTransmission() == 0) {
            Serial.print("Found at 0x");
            Serial.println(address, HEX);
        }
    }

    Serial.println("Done");
}

void loop() {}