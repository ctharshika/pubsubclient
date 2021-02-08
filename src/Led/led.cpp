#include "led.h"

#include "Timer/software_timer.h"

/* local types & variables */
typedef enum LedStates
{
    IDLE = 0,
    OFF,
    ON,
    TOGGLE,
    BLINK
} ledstate_t;

software_timer_t timer_period;
software_timer_t timer_duration;
uint8_t led_gpio;
ledstate_t led_state;

/* private functions prototypes */
void led_toggle();

/* public functions */
void led_init(uint8_t gpio_pin)
{
    led_gpio = gpio_pin;
    led_state = OFF;
    pinMode(led_gpio, OUTPUT);
    digitalWrite(led_gpio, 0);
}

void led_set(uint8_t value)
{
    if (value)
    {
        led_state = ON;
    }
    else
    {
        led_state = OFF;
    }
}

void led_set_toggle()
{
    led_state = TOGGLE;
}

void led_set_blink(uint32_t period_ms)
{
    led_set_blink(period_ms, 0);
}

void led_set_blink(uint32_t period_ms, uint32_t duration_ms)
{
    led_state = BLINK;
    software_timer_set(&timer_period, period_ms);
    software_timer_set(&timer_duration, duration_ms);
}

void led_process()
{
    switch (led_state)
    {
    case OFF:
        digitalWrite(led_gpio, 0);
        led_state = IDLE;
        break;

    case ON:
        digitalWrite(led_gpio, 1);
        led_state = IDLE;
        break;

    case TOGGLE:
        led_toggle();
        led_state = IDLE;
        break;

    case BLINK:
        if (!software_timer_expired(&timer_duration) || software_timer_get_duration(&timer_duration) == 0)
        {
            if (software_timer_expired(&timer_period))
            {
                led_toggle();
                software_timer_restart(&timer_period);
            }
        }
        else if (software_timer_get_duration(&timer_duration) != 0)
        {
            led_state = IDLE;
        }
        break;

    case IDLE:
    default:
        break;
    }
}

/* private functions */
void led_toggle()
{
    uint8_t value = digitalRead(led_gpio);
    value ^= 1;
    digitalWrite(led_gpio, value);
}