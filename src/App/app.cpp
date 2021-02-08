
#include "app.h"
#include "Button/button.h"
#include "Led/led.h"
#include "Oled/oled.h"

void app_init()
{

}

void app_process()
{

}

void button_press_cb(uint8_t click_count)
{

}

void button_released_cb(uint8_t click_count)
{
 
}

void button_long_press_cb()
{
    oled_clear();
    oled_print("Long press");
}