#include<assert.h>
#include<sys/select.h>
#include<unistd.h>
#include<sys/time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

#include "network.h"


/**
 * This is the main loop of this program.
 */
void handle_events(void) {
	int max_fd = my_udp_socket + 1;
	fd_set          read_set;
	struct timeval  tv;
	int             retval;

	while( 1 ) {
		FD_ZERO(&read_set);
		FD_SET(my_udp_socket, &read_set);	/* add listening UDP sock */

		/* Now wait until something happens.
		*/
		tv.tv_sec = 0;
		tv.tv_usec = 100000;
		retval = select(max_fd, &read_set, 0, 0, &tv);

		switch(retval) {
			case -1 :
				perror( "Error in select" );
				break;

			case 0 :
				break;

			default :
				/* If this file descriptor is set, something has happened on
				 * the UDP socket. Probably data has arrived. Call the event
				 * handler in network.
				 */
				if(FD_ISSET(my_udp_socket, &read_set)) {
					net_handle_event();

				}
				break;
		}
	}
}

