#include <Arduino.h>
#include "led.h"

void setup() {
    led_init();
}

void loop() {
    led_on();
    delay(1000);
    led_off();
    delay(1000);
}
