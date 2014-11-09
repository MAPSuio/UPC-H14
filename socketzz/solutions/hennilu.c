#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

static int my_udp_socket = 0;
static int BUF_SIZ = 256;

/**
 * Called at the start of the program. Initializes data structures
 * like an operating system would do at boot time.
 *
 * local_port is the port that for the local UDP socket that is used for all 
 * communication.
 *
 * This function initializes a socket for the server.
 */
void net_init(int local_port) 
{
	struct sockaddr_in addr;
	int err;

	my_udp_socket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if(my_udp_socket < 0) {
		_ERR("Failed to create local UDP socket");
		exit(-1);
	}

	memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_family      = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port        = htons(local_port);

	/* Bind to the socket */
	err = bind(my_udp_socket, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));

	if(err < 0) {
		_ERR("Failed to bind local UDP socket to port %d", local_port);
		exit(-1);
	}
}

void net_recv()
{
	struct sockaddr_in src_addr;
	socklen_t addrlen = sizeof(struct sockaddr_in);

	char buffer[BUFFER_SIZ];
	memset(buffer, 0, (sizeof(char) * BUF_SIZ));

	ssize_t recvd_bytes = 0;

	recvd_bytes = recvfrom(my_udp_socket, &buffer, (sizeof(char) * BUF_SIZ), 0, 
                            (struct sockaddr*) &src_addr, &addrlen);

	if (recvd_bytes < 0) {
		_ERR("Failed to recv data:");
		perror("recvfrom()");
		return;
	} 

    buffer[recvd_bytes - 1] = '\0'; // Null terminate for prettyness

    printf("Message received: %s\n", buffer);
}

int main(int argc, char** argv)
{
    int local_port = 3950;

    net_init(local_port);
    return 0;
}
