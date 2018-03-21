#include "stdio.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <math.h>
#include <string.h>

#include <sched.h>

#include "../inc/main.h"

int main()
{
	int rows, columns;

	initscr();   // start curses ***
	getmaxyx(stdscr, rows, columns);
	clear();
	noecho();
	cbreak();

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);

	attron(COLOR_PAIR(3));

	struct timespec sleep_interval;

	sleep_interval.tv_sec = 0;
	sleep_interval.tv_nsec = 10000000;	// 10 miliseconds

	time_t start_time, current_time;

	start_time = time(NULL);
	
	pthread_t one_hz_timer_thread_handle;
	pthread_t ten_hz_timer_thread_handle;
	pthread_t one_minute_timer_thread_handle;
	int threadId;
	int parameter = 0;
	
	// start threads 
	pthread_create(&one_hz_timer_thread_handle, NULL, one_hz_timer_thread, NULL);
	pthread_create(&ten_hz_timer_thread_handle, NULL, ten_hz_timer_thread, NULL);
	pthread_create(&one_minute_timer_thread_handle, NULL, one_minute_timer_thread, NULL);

	int i, j, k;



	while(1)
	{

		current_time = time(NULL);

		move(0, 0);	
		printw("Hello, Master!");
		move(1, 0);	
		printw("start   -> %s", ctime(&start_time));
		move(2, 0);	
		printw("current -> %s", ctime(&current_time));
		move(3, 0);	
		printw("%d", get_one_minute_timer_counter());
		move(4, 0);	
		printw("%d", get_one_hz_timer_counter());
		move(5, 0);	
		printw("%d", get_ten_hz_timer_counter());
		refresh();

		nanosleep(&sleep_interval, NULL);
	}


	//getch();

	endwin();

	return 0;
}
