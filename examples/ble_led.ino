#include <SoftwareSerial.h>

SoftwareSerial bleSerial(10, 11); // RX, TX - compatible with the providing Fritzing diagram

int ledPin = 13;

void setup() {
  // This is what it was set to on my module, you may have to change it
  bleSerial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
if (bleSerial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = bleSerial.read();
    // if it's a capital O turn on the LED:
    if (incomingByte == 'O') {
      digitalWrite(ledPin, HIGH);
    }
    // if its a capital F turn off the LED:
    if (incomingByte == 'F') {
      digitalWrite(ledPin, LOW);
    }
  }
}
