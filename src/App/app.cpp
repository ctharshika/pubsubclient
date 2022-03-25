#include "app.h"
#include "Button/button.h"
#include "Led/led.h"
#include "Oled/oled.h"

int variable=0;

void app_init()
{
    led_set(1);

}



void app_process()
{

}

void button_press_cb(uint8_t click_count)
{

}

void button_released_cb(uint8_t click_count)
{
 if (click_count ==1){
     oled_clear();
     led_set_toggle();
 }
 else if (click_count ==2){
     variable = variable +1;
     oled_clear();
     oled_print(String(variable));
     led_set_blink(1000);
 }

}

void button_long_press_cb()
{
    oled_clear();
    oled_print("Long press");
    led_set_blink(500,6300); 

}
