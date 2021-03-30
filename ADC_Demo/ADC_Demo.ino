/*
  ADC Demo

    Reads analog value (via ADC - 12bit resolution) from PA1 pin.
    
    Oscilloscope check: Probe on PA1 pins.

*/

int analogPin = PA1; // analog pin PA1
                    
int val = 0;  // variable to store the value read

void setup() {
  Serial.begin(115200);           //  setup serial
   
  pinMode(analogPin, INPUT_ANALOG);
  analogReadResolution(12);
  
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  Serial.print("PA1=");          // debug value
  Serial.println(val);          // debug value

  delay(1000);
}
