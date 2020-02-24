#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // Change to whatever you hooked
                                 // RX, TX up to

void setup() {
 mySerial.begin(9600);
}

void loop() {
 for (int i=0; i<255; i++) {
 mySerial.write(i);
 delay(100);
 }
 for (int i=255; i>0; i--) {
 mySerial.write(i);
 delay(100);
 }
}
