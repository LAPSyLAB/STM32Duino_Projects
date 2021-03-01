/*
  FreeRTOS_Demo

  Simple demo of three threads
  LED blink thread, print thread, and idle loop


  Oscilloscope check: Probe on PD12-PD15 pins.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
#include <STM32FreeRTOS.h>

const uint8_t LED_PIN = PD12;
const uint8_t LED_PIN1 = PD13;
const uint8_t LED_PIN2 = PD14;
const uint8_t LED_PIN3 = PD15;

volatile uint32_t count = 0;

// handle for blink task
TaskHandle_t blink;

//------------------------------------------------------------------------------
// high priority for blinking LED
static void vLEDFlashTask(void *pvParameters) {
  pinMode(LED_PIN, OUTPUT);

  // Flash led every 200 ms.
  for (;;) {
    // Turn LED on.
    digitalWrite(LED_PIN, HIGH);

    // Sleep for 50 milliseconds.
    vTaskDelay((50L * configTICK_RATE_HZ) / 1000L);

    // Turn LED off.
    digitalWrite(LED_PIN, LOW);

    // Sleep for 150 milliseconds.
    vTaskDelay((150L * configTICK_RATE_HZ) / 1000L);
  }
}
//------------------------------------------------------------------------------
static void vPrintTask(void *pvParameters) {

  while (1) {
    digitalWrite(LED_PIN1, HIGH);
   // Sleep for one second.
    vTaskDelay(configTICK_RATE_HZ);
    digitalWrite(LED_PIN1, LOW);

    // Print count for previous second.
    Serial.print(F("Count: "));
    Serial.print(count);

    // Print unused stack for threads.
    Serial.print(F(", Unused Stack: "));
    Serial.print(uxTaskGetStackHighWaterMark(blink));
    Serial.print(' ');
    Serial.print(uxTaskGetStackHighWaterMark(0));
    Serial.print(' ');
    Serial.println(uxTaskGetStackHighWaterMark(xTaskGetIdleTaskHandle()));

   // Sleep for one second.
    vTaskDelay(configTICK_RATE_HZ);
    // Zero count.
    count = 0;
  }
}
//------------------------------------------------------------------------------
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);


  
  Serial.begin(9600);

  
    digitalWrite(LED_PIN3, HIGH);
    delay(1000);                       // wait for a second
    digitalWrite(LED_PIN3, LOW);
    delay(1000);                       // wait for a second
    digitalWrite(LED_PIN3, HIGH);
    delay(1000);                       // wait for a second
    digitalWrite(LED_PIN3, LOW);
    delay(1000);                       // wait for a second
    digitalWrite(LED_PIN3, HIGH);

  // create blink task
  xTaskCreate(vLEDFlashTask,
    "Task1",
    configMINIMAL_STACK_SIZE + 50,
    NULL,
    tskIDLE_PRIORITY + 2,
    &blink);

  // create print task
  xTaskCreate(vPrintTask,
    "Task2",
    configMINIMAL_STACK_SIZE + 100,
    NULL,
    tskIDLE_PRIORITY + 1,
    NULL);

  // start FreeRTOS
  vTaskStartScheduler();

  // should never return
  Serial.println(F("Die"));
  while(1);
}
//------------------------------------------------------------------------------
// WARNING idle loop has a very small stack (configMINIMAL_STACK_SIZE)
// loop must never block
void loop() {
  while(1) {

    digitalWrite(LED_PIN2, HIGH);

    // must insure increment is atomic
    // in case of context switch for print
    noInterrupts();
    count++;
    interrupts();
   digitalWrite(LED_PIN2, LOW);
  }
}
