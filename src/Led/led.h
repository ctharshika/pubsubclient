#ifndef __LED_INCLUDED__
#define __LED_INCLUDED__

#include "bsp.h"

void led_init(uint8_t gpio_pin);
void led_set(uint8_t value);
void led_set_toggle();
void led_set_blink(uint32_t interval_ms);
void led_set_blink(uint32_t interval_ms, uint32_t duration_ms);
void led_process();

#endif



