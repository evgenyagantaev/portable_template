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

	int i, j, k;



	while(1)
	{
		move(7, 11);	
		printw("Hello, Master!");
		refresh();
		//sleep(1);
		nanosleep(&sleep_interval, NULL);
	}


	//getch();

	endwin();

	return 0;
}
