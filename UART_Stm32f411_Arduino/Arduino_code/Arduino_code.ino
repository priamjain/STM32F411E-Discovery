#include <SoftwareSerial.h>
String a;

SoftwareSerial mySerial (0,1);
void setup() {

Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

mySerial.begin(9600);
}

void loop() {
while(mySerial.available()) {

a= mySerial.readString();// read the incoming data as string

Serial.println(a);
}
mySerial.flush();

}
