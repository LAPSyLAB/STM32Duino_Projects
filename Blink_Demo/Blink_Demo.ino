/*
  Blink_Demo

  Turns an LEDs on for one second, then off for one second, repeatedly.
  Also, prints are sent do USB CDC UART.

  Oscilloscope check: Probe on PD12-PD15 pins.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
#include <Arduino.h>

// the setup function runs once when you press reset or power the board
void setup() {
  
  pinMode(PD12, OUTPUT);
  pinMode(PD13, OUTPUT);
  pinMode(PD14, OUTPUT);
  pinMode(PD15, OUTPUT);
 
  Serial.begin();
  Serial.println("USB:Hello World");

}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(PD12, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PD13, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PD14, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PD15, HIGH);   // turn the LED on (HIGH is the voltage level)

  delay(1000);                       // wait for a second

  digitalWrite(PD12, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(PD13, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(PD14, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(PD15, LOW);    // turn the LED off by making the voltage LOW

  delay(1000);                       // wait for a second
  Serial.println("USB:2 secs");
  
}
