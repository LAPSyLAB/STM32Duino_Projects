// read analog pin and print it via software serial
// STM32F4 Discovery

#define ANALOGPIN                  PA1


#define USERBUTTON                 PA0

#define GREENLED                  PD12
#define ORANGELED                 PD13
#define GREDLED                   PD14
#define BLUELED                   PD15
#define REDLEDOTGOVERCURRENT       PD5

              
#define NUMLEDS 5
const uint8_t Led[] = {GREENLED, ORANGELED, GREDLED, BLUELED, REDLEDOTGOVERCURRENT};


void setup()
{
  Serial.begin(115200);
  
  for (int n = 0; n < NUMLEDS; n++)  pinMode(Led[n], OUTPUT);
  pinMode(ANALOGPIN, INPUT_ANALOG);
}

void setLed(uint8_t n, uint8_t state)
{
  digitalWrite(Led[n], state);
}


void loop()
{
    Serial.println(analogRead(ANALOGPIN));
 
    delay(500);    
}
