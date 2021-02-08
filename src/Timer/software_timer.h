#ifndef __SOFTWARE_TIMER_INCLUDED__
#define __SOFTWARE_TIMER_INCLUDED__

#include "bsp.h"

typedef struct {
	uint32_t start_time;
	uint32_t duration;
}software_timer_t;

void software_timer_set(software_timer_t *t, uint32_t duration_ms);
uint32_t software_timer_get_duration(software_timer_t *t);
void software_timer_reset(software_timer_t *t);
void software_timer_restart(software_timer_t *t);
uint32_t software_timer_elapsed(software_timer_t *t);
uint32_t software_timer_remaining(software_timer_t *t);
uint8_t software_timer_expired(software_timer_t *t);

#endif