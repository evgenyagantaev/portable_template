#include "../inc/ten_hz_timer_obj.h"


void *ten_hz_timer_thread(void *parameter_pointer)
{

	ten_hz_sleep_interval.tv_sec = 0;
	ten_hz_sleep_interval.tv_nsec = 100000000;	// 100 miliseconds

	while(1)
	{
		nanosleep(&ten_hz_sleep_interval, NULL);
		increment_ten_hz_timer_counter();
	}

	return NULL;
}

uint32_t get_ten_hz_timer_counter()
{
	return ten_hz_timer_counter;
}
void increment_ten_hz_timer_counter()
{
	ten_hz_timer_counter++;
}
