#include <SoftwareSerial.h> 
  // Define the pins for the bluetooth module
SoftwareSerial mySerial(10, 8); // RX | TX 


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  // Open serial communication for the Bluetooth Serial Port
  mySerial.begin(9600);
}

void loop() {
  // If any data is available at the Bluetooth Serial Port
  if (mySerial.available()) {
    // Write this data to the Serial Monitor (Arduino)
    Serial.write(mySerial.read());
  }

  // If any data is sent via the Serial Monitor (Arduino)
  if (Serial.available()) {
    // Send this data via the Bluetooth Serial Port
    mySerial.write(Serial.read());
  }
}
