#include "../inc/one_hz_timer_obj.h"


void *one_hz_timer_thread(void *parameter_pointer)
{

	one_hz_sleep_interval.tv_sec = 1;
	one_hz_sleep_interval.tv_nsec = 0;	// 10 miliseconds

	while(1)
	{
		nanosleep(&one_hz_sleep_interval, NULL);
		increment_one_hz_timer_counter();
	}

	return NULL;
}

uint32_t get_one_hz_timer_counter()
{
	return one_hz_timer_counter;
}
void increment_one_hz_timer_counter()
{
	one_hz_timer_counter++;
}
