#include "oled.h"

#define OLED_WIDTH 128
#define OLED_HEIGHT 64

/* local types & variables */
typedef enum OledStates
{
    IDLE = 0,
    CLEAR,
    PRINT
} oledstate_t;

U8G2_SSD1306_128X64_NONAME_F_HW_I2C *u8g2;

uint8_t cursor_y = 0;
oledstate_t oled_state;

/* private functions prototypes */

/* public functions */
void oled_init(uint8_t reset_gpio_pin, uint8_t scl_pin, uint8_t sda_pin)
{
    u8g2 = new U8G2_SSD1306_128X64_NONAME_F_HW_I2C(U8G2_R0, reset_gpio_pin, scl_pin, sda_pin);
    u8g2->begin();
    u8g2->setFont(u8g2_font_t0_11_mf);
    cursor_y = u8g2->getMaxCharHeight();
}

void oled_print(String message)
{
    uint8_t cursor_x = 0;
    uint8_t message_len = u8g2->getUTF8Width(message.c_str());

    if (OLED_WIDTH - message_len > 0)
    {
        cursor_x = (OLED_WIDTH - message_len) / 2;
    }

    if (cursor_y > OLED_HEIGHT)
    {
        cursor_y = u8g2->getMaxCharHeight();
        u8g2->clear();
    }

    u8g2->drawUTF8(cursor_x, cursor_y, message.c_str());
    cursor_y += u8g2->getMaxCharHeight();
    oled_state = PRINT;
}

void oled_process()
{
    if (oled_state == PRINT)
    {
        u8g2->sendBuffer();
        oled_state = IDLE;
    }
    else if (oled_state == CLEAR)
    {
        cursor_y = u8g2->getMaxCharHeight();
        u8g2->clear();
        oled_state = IDLE;   
    }
}

void oled_clear()
{
    oled_state == CLEAR;
}

/* private functions */