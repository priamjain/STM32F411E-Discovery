#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
  pinMode(7,OUTPUT);
}

void loop() {
 
    Serial.println("t");
  Wire.beginTransmission(8); // transmit to device #8       // sends five bytes
  Wire.write("123");// 1234--> all leds will glow 
   Wire.endTransmission();
 
   Wire.requestFrom(8, 3);    // request 6 bytes from slave device #8
Serial.println("t2");
  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
    
  }
    Serial.println("t3");

   
  
}
