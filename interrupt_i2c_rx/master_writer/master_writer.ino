// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
  pinMode(7,OUTPUT);
}

void loop() {
  if(Serial.read()=='4')
  {   
    Serial.println("t");
  Wire.beginTransmission(8); // transmit to device #8       // sends five bytes
  Wire.write("12841");// 1234--> all leds will glow 
   Wire.endTransmission();
   Wire.requestFrom(8, 5);    // request 6 bytes from slave device #8
   delay(10);
Serial.println("t2");
  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
    Serial.println("t3");
  }

  }
  
  
}
