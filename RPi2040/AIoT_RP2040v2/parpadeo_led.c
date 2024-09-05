/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "Arduino.h"
#include "pico/stdlib.h"
#include "stdbool.h"

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 3000
#endif

// Initialize the GPIO for the LED
void pico_led_init(void)
{
  // A device like Pico that uses a GPIO for the LED will define PICO_DEFAULT_LED_PIN
  // so we can use normal GPIO functionality to turn the led on and off
  gpio_init(PICO_DEFAULT_LED_PIN);
  gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
}

// Turn the LED on or off
void pico_set_led()
{
  // Just set the GPIO on or off
  gpio_put(PICO_DEFAULT_LED_PIN, !gpio_get(PICO_DEFAULT_LED_PIN));
}

int main()
{
  pico_led_init();
  for(;;)
  {
    pico_set_led();
    sleep_ms(LED_DELAY_MS);
  }
}