#include <time.h>


static uint32_t one_hz_timer_counter = 0;

static struct timespec one_hz_sleep_interval;





uint32_t get_one_hz_timer_counter();
void increment_one_hz_timer_counter();

void *one_hz_timer_thread(void *parameter_pointer);
