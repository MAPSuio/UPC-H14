#ifndef NETWORK
#define NETWORK

#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>

#define HELLO	0x01
#define GET 	0x02
#define ANSWER	0x03
#define ERROR	0x04

/* Struct is used to hold the network message */
struct __attribute__((__packed__)) Protocol
{
	uint8_t total_size;
	uint8_t type;
	uint8_t input1;
	uint8_t input2;
};
typedef struct Protocol net_message_t;



/*
 * This is the one UDP socket that is used for all sending
 * and receiving. The select loop must know it.
 */
extern int my_udp_socket;

/* see more comments in the c file */

void net_init(int local_port);
int reply_hash(struct sockaddr_in* addr, socklen_t addrlen, const char* buf);
unsigned long hash(unsigned char *str);
size_t net_send(struct sockaddr_in* addr, socklen_t addrlen,  const char* buf, int length);
void net_handle_event(void);


#endif

