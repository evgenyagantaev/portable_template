#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include "one_hz_timer_obj.h" 


#define TRANSMIT_PORT 1112

static struct timespec udp_transmit_sleep_interval;

static int transmit_socket;
static struct sockaddr_in transmit_address;

static char udp_transmit_message[1024];

void *udp_transmitter_thread(void *parameter_pointer);
