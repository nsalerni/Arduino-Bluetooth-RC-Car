#include <PS3BT.h>
#include <usbhub.h>

// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif

USB Usb;

BTD Btd(&Usb); // Create the Bluetooth Dongle instance
PS3BT PS3(&Btd, 0x00, 0x15, 0x83, 0x4C, 0x33, 0xD3); // Telnet Bluetooth Adapter (with MAC Address)

// Motor Pins
int motorPin1 =  5;    // One motor wire connected to digital pin 5
int motorPin2 =  6;    // One motor wire connected to digital pin 6
int motorPin3 =  9;    // One motor wire connected to digital pin 9

// The setup() method runs once, when the sketch starts
void setup()   
{                
  // initialize the digital pins as an output:
  pinMode(motorPin1, OUTPUT); 
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);  
  
  Serial.begin(115200);
  while (!Serial); // Wait for serial port to connect
  if (Usb.Init() == -1) 
  {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
}

// The loop() method runs over and over again,
// as long as the Arduino has power
void loop()                     
{
  Usb.Task();
  
  // Turn Right.
  if (PS3.getButtonPress(LEFT))
  {
    analogWrite(motorPin1, 255);  // rotates motor
    digitalWrite(motorPin2, LOW); // set the Pin motorPin2 LOW
  }
  // Turn Left.
  if (PS3.getButtonPress(RIGHT))
  {
     analogWrite(motorPin2, 255);  // rotates motor
     digitalWrite(motorPin1, LOW); // set the Pin motorPin1 LOW
  }
  // Forward.
  if(PS3.getButtonPress(CROSS))
  {
     analogWrite(motorPin3, 0); // rotates motor
  }
  // Turn all off.
  else
  {
    digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
    digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
    analogWrite(motorPin3, 255);     // turns motor 3 off
  }
}
