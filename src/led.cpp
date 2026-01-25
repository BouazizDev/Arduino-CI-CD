#include <Arduino.h>
#include "led.h"

#define LED_PIN 13

void led_init() {
    pinMode(LED_PIN, OUTPUT);
}

void led_on() {
    digitalWrite(LED_PIN, HIGH);
}

void led_off() {
    digitalWrite(LED_PIN, LOW);
}
