#include <driver/rtc_io.h>
#define LED_PIN    22

void setup() {
  Serial.begin(115200);
  rtc_gpio_pulldown_en((gpio_num_t)GPIO_NUM_12);                  //Enables ESP32 pullup or pulldown resistor during deep sleep
  esp_sleep_enable_ext0_wakeup((gpio_num_t)GPIO_NUM_12, RISING);
}

void loop() {
  Flash_LED();
  Serial.println("Going to sleep...");
  esp_deep_sleep_start();  // Sleep for ever until switch pressed
}

void Flash_LED() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
