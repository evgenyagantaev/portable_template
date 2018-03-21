#include <time.h>


static uint32_t ten_hz_timer_counter = 0;

static struct timespec ten_hz_sleep_interval;





uint32_t get_ten_hz_timer_counter();
void increment_ten_hz_timer_counter();

void *ten_hz_timer_thread(void *parameter_pointer);
