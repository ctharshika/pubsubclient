#include "bsp.h"

#include "App/app.h"
#include "Button/button.h"
#include "Led/led.h"
#include "Oled/oled.h"

void setup(void)
{   
    button_init(BUTTON_GPIO);
    led_init(LED_GPIO);
    oled_init(SSD1306_RESET_GPIO, SSD1306_SCL_GPIO, SSD1306_SDA_GPIO);
    app_init();
}

void loop(void)
{
    button_process();
    led_process();
    oled_process();
    app_process();
}