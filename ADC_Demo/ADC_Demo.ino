/*
  ADC Demo

    Oscilloscope check: Probe on PA1 pins.

*/

int analogPin = PA1; // potentiometer wiper (middle terminal) connected to analog pin PA1
                    // outside leads to ground and +5V
                    
int val = 0;  // variable to store the value read

void setup() {
  Serial.begin(115200);           //  setup serial
   
  pinMode(analogPin, INPUT_ANALOG);
  analogReadResolution(12);
  
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  Serial.println(val);          // debug value

  delay(500);
}
