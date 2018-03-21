#include <time.h>


static uint32_t one_minute_timer_counter = 0;

static struct timespec one_minute_sleep_interval;





uint32_t get_one_minute_timer_counter();
void increment_one_minute_timer_counter();

void *one_minute_timer_thread(void *parameter_pointer);
