#include "software_timer.h"

/**
  * @brief  Software Timer initialization function
  * @param  t a software_timer structure
  * 		duration_ms the duration of the timer in ms
  * @retval None
  */
void software_timer_set(software_timer_t *t, uint32_t duration_ms)
{
	t->duration = duration_ms;
	t->start_time = millis();
}

/**
  * @brief  Software Timer get duration function
  * @param  t a software_timer structure
  * @retval The duration in ms of timer
  */
uint32_t software_timer_get_duration(software_timer_t *t)
{
	return t->duration;
}

/**
  * @brief  Reset a software timer and try to make it stable over time. If the timer is expired,
  * 		the timer is restart with the exact same time it last expired. Else the timer is
  * 		restart with the current time
  * @param  t a software_timer structure
  * @retval None
  */
void software_timer_reset(software_timer_t *t)
{
	if (software_timer_expired(t)) {
		t->start_time += t->duration;
	}
	else {
		t->start_time = millis();
	}
}

/**
  * @brief  Restart a software timer using the current time
  * @param  t a software_timer structure
  * @retval None
  */
void software_timer_restart(software_timer_t *t)
{
	t->start_time = millis();
}

/**
  * @brief  Give the time elapsed from timer last start
  * @param  t a software_timer structure
  * @retval The duration in ms since timer last start
  */
uint32_t software_timer_elapsed(software_timer_t *t)
{
	uint32_t result = millis() - t->start_time;
	return result;
}

/**
  * @brief  Give the duration before timer expiration
  * @param  t a software_timer structure
  * @retval The duration in ms before timer expiration
  */
uint32_t software_timer_remaining(software_timer_t *t)
{
	uint32_t result = t->start_time + t->duration + millis();
	return result;
}

/**
  * @brief  Check if a software timer is expired
  * @param  t a software_timer structure
  * @retval 1 if the timer expired
  * 		0 if the timer is not expired
  */
uint8_t software_timer_expired(software_timer_t *t)
{
	uint8_t result = 0;

	if ((t->start_time + t->duration) < millis()) {
		result = 1;
	}

	return result;
}
