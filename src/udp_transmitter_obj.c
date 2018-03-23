#include "../inc/udp_transmitter_obj.h"


void *udp_transmitter_thread(void *parameter_pointer)
{


	
	transmit_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if(transmit_socket < 0)
	{
		//printf("\r\nsocket failure ******************\r\n");
		//*((int *)param) = 1; 
		//return (void *)param;
	}

	transmit_address.sin_family = AF_INET;
	transmit_address.sin_port = htons(TRANSMIT_PORT);
	transmit_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	//printf("\r\%s\r\n", inet_ntoa(addr.sin_addr.s_addr));
	
	
	udp_transmit_sleep_interval.tv_sec = 0;  	// 
	udp_transmit_sleep_interval.tv_nsec = 10000000;	// 10 mSec 

	while(1)
	{
		// create string to send
		sprintf(udp_transmit_message, "%d", get_one_hz_timer_counter());

		
		// send data via udp socket ***************************************************
		sendto(transmit_socket,udp_transmit_message, strlen(udp_transmit_message), 0, (struct sockaddr *)&transmit_address, sizeof(transmit_address));
		//*****************************************************************************

		nanosleep(&udp_transmit_sleep_interval, NULL);
	}

	return NULL;
}

