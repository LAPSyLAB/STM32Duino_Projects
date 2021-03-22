/*
  Blink_Key_Demo

  Turns an LEDs on/off according to the state of user button.
  Also, prints are sent do USB CDC UART.

  Oscilloscope check: Probe on PD12-PD15 pins.

  */
#include <Arduino.h>

#define USERBUTTON                 PA0

#define GREENLED                  PD12
#define ORANGELED                 PD13
#define REDLED                   PD14
#define BLUELED                   PD15

#define NUMLEDS 4
const uint8_t Led[] = {GREENLED, ORANGELED, REDLED, BLUELED};
uint8_t state = 0;

void setLed(uint8_t n, uint8_t state)
{
  for (int i = 0; i < n; i++) 
    digitalWrite(Led[i], state);
}

// the setup function runs once when you press reset or power the board
void setup() {

  for (int n = 0; n < NUMLEDS; n++)  
      pinMode(Led[n], OUTPUT);
  
  pinMode(USERBUTTON, INPUT);

  Serial.begin();
  Serial.println("USB:Hello World");

}

// the loop function runs over and over again forever
void loop() {
  
  state = digitalRead(USERBUTTON); 
  setLed(NUMLEDS, state);
   
  delay(1000);                       // wait for a second
  Serial.println("USB:1 sec");

}
