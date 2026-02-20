#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN28_PIN = 28;
const int BTN26_PIN = 26;
const int LED_PIN_R = 4;
const int LED_PIN_G = 6;
bool led_r = false;
bool led_g = false;

int main() {
  stdio_init_all();
  gpio_init(BTN28_PIN);
  gpio_init(BTN26_PIN);
  gpio_set_dir(BTN28_PIN, GPIO_IN);
  gpio_set_dir(BTN26_PIN, GPIO_IN);
  gpio_pull_up(BTN28_PIN);
  gpio_pull_up(BTN26_PIN);
  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);
  while (true) {
    if (!gpio_get(BTN28_PIN)) {
      led_r = !led_r;
      gpio_put(LED_PIN_R, led_r);
      while (!gpio_get(BTN28_PIN)) {
                sleep_ms(10); 
            }
            sleep_ms(50);
    }
    if (!gpio_get(BTN26_PIN)) {
      led_g = !led_g;
      gpio_put(LED_PIN_G, led_g);
      while (!gpio_get(BTN26_PIN)) {
                sleep_ms(10);
            }
            sleep_ms(50);
    }
  }
}
