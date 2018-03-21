#include "../inc/one_minute_timer_obj.h"


void *one_minute_timer_thread(void *parameter_pointer)
{

	one_minute_sleep_interval.tv_sec = 60;  // 1 minute
	one_minute_sleep_interval.tv_nsec = 0;	// 

	while(1)
	{
		nanosleep(&one_minute_sleep_interval, NULL);
		increment_one_minute_timer_counter();
	}

	return NULL;
}

uint32_t get_one_minute_timer_counter()
{
	return one_minute_timer_counter;
}
void increment_one_minute_timer_counter()
{
	one_minute_timer_counter++;
}
