#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "log.h"

static int udp_socket = 0;
static int BUF_SIZ = 256;
static int PORT = 3950;

void net_init() 
{
	udp_socket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if(udp_socket < 0) {
		_ERR("Failed to create local UDP socket");
        perror("socket()");
		exit(-1);
	}
}

void net_send()
{
    struct sockaddr_in addr;
    int retval;
    char msg[256];
    int msg_size;

	memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_family      = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port        = htons(PORT);

    msg_size = create_message(msg);

    retval = sendto(udp_socket, msg, msg_size, 0, (struct sockaddr *) &addr, sizeof(addr));

    if (retval == -1) {
        _ERR("Sendto failed: ");
        perror("sendto()");
        exit(-1);
    }
}

void net_recv()
{
	struct sockaddr_in src_addr;
	socklen_t addrlen = sizeof(struct sockaddr_in);

	char buffer[BUF_SIZ];
	memset(buffer, 0, (sizeof(char) * BUF_SIZ));

	ssize_t recvd_bytes = 0;

	recvd_bytes = recvfrom(udp_socket, &buffer, (sizeof(char) * BUF_SIZ), 0, 
                            (struct sockaddr*) &src_addr, &addrlen);


	if (recvd_bytes < 0) {
		_ERR("Failed to recv data:");
		perror("recvfrom()");
        exit(-1);
	} 

    printf("%s\n", &buffer[sizeof(uint8_t) * 4]);
}

int create_message(char* msg)
{
    /* Data types */
    uint8_t length;
    uint8_t type;
    uint8_t input1;
    uint8_t input2;

    /* Message size */
    int size = sizeof(uint8_t) * 4;

    /* Indexes */
    int length_index;
    int type_index;
    int input1_index;
    int input2_index;

    /* Data assignation */
    length = size;
    type   = 0x02;
    input1 = 0x17;
    input2 = 0x07;

    /* Index declaration */
    length_index = 0;
    type_index   = 1;
    input1_index = 2;
    input2_index = 3;

    /* Inserting into message */
    msg[length_index] = length;
    msg[type_index]   = type;
    msg[input1_index] = input1;
    msg[input2_index] = input2;

    return size;
}

int main(int argc, char** argv)
{
    net_init();
    net_send();
    net_recv();
    return 0;
}
