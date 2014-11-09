#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<unistd.h>

#include "network.h"
#include "log.h"

int my_udp_socket = -1;


/**
 * Called at the start of the program. Initializes data structures
 * and binding a socket to the specified port.
 *
 * local_port is the port that for the local UDP socket that is used for all 
 * communication. Given in main()
 *
 * This function initializes a socket for the server.
 */
void net_init(int local_port) {
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

/**
 * When select notices that data for my_udp_socket has arrived, it calls
 * this function.
 *
 * A positive return value means that all data has been delivered.
 * A zero return value means that the receiver can not receive the
 * data right now.
 * A negative return value means that an error has occured and
 * receiving failed.
 */
void net_handle_event(void) {

	/* Storing source of the data that has arrived. */
	struct sockaddr_in src_addr;
	socklen_t addrlen = sizeof(struct sockaddr_in);

	/* Initialize and clean recv framebuffer */
	char buffer[256]; // 8bit msg-> size
	memset(buffer, 0, sizeof(buffer));

	/* Start recieving from the socket and store in buffer*/
	ssize_t recvd_bytes = 0;
	recvd_bytes = recvfrom(my_udp_socket, &buffer, sizeof(buffer), 0,
			(struct sockaddr*) &src_addr, &addrlen);

	_INFO("Got %d bytes from client X", recvd_bytes);

	if (recvd_bytes < 0) {
		_ERR("Failed to recv data:");
		perror("recvfrom()");
		return;
	} 

	int retval = 0;
	net_message_t* msg = (net_message_t*) buffer;
	int kind = msg->type;

	if (kind == HELLO) {
		_INFO("Got HELLO from client at X");
		retval = hello(&src_addr, addrlen, buffer);
			
	} else if (kind == GET) {
		retval = reply_hash(&src_addr, addrlen, buffer);
		if (retval < 0) {

			printf("error in reply_hash\n");
			//	reply_error(src_addr, addrlen);
		}
	}

	else if (kind == ANSWER) {

		// used for testing 
	} else {
		_ERR("Got jibberish from client X");
		// protocoll error send back error 
	}
}

/**
 * Called when we recieve a msg->type HELLO. Used for testing the protocol.
 *
 */
int hello(struct sockaddr_in* addr, socklen_t addrlen) {
	
	char* sendbuf;
	char* text = "Hello!";
	size_t msg_length = strlen(text) + sizeof(net_message_t);

	sendbuf = malloc(msg_length);
	net_message_t* reply_msg = (net_message_t*) sendbuf;


	reply_msg->total_size = (uint8_t) msg_length;
	reply_msg->type = HELLO; // maybe add a HELLORPLY
	memcpy(&sendbuf[sizeof(net_message_t), text, strlen(text)]);

	int rv = net_send(addr, addrlen, sendbuf, msg_length);
	free(sendbuf);
	return rv;
}


/**
 * Called when we recive msg_type GET. This function
 * generates the hash, and replys it to the sender
 *
 */
int reply_hash(struct sockaddr_in* addr, socklen_t addrlen, const char* buf) {

	/* extract input from client */
	net_message_t* msg = (net_message_t*) buf;
	char a = msg->input1 + 65;
	char b = msg->input2 + 65;

	char* s = "alittlestring";
	char* input = malloc(strlen(s) + 2);
	sprintf(input,"%s%c%c\0", s, a, b);

	char key[256 - sizeof(net_message_t)];
	sprintf(key, "%d\0", hash(s));
	size_t msg_length = strlen(key) + sizeof(net_message_t);

	char* sendbuf = (char*) malloc(msg_length);
	if (!sendbuf) {
		exit(-1);
	}

	net_message_t* reply_msg = (net_message_t*) sendbuf;

	reply_msg->total_size = (uint8_t) msg_length;
	reply_msg->type = ANSWER;
	reply_msg->input1 = 0x0;
	reply_msg->input2 = 0x0;
	memcpy(&sendbuf[sizeof(net_message_t)], key, strlen(key));

	int rv = net_send(addr, addrlen, sendbuf, msg_length);
	free(sendbuf);
	free(input);
	return rv;

}

/*
 * DJB2 hash 
 */
unsigned long hash(unsigned char *str) {
	unsigned long hash = 53814545451;
	int c;

	while (c = *str++) {
		hash = ((hash << 5) + hash) + c;
	}
	return hash;
}



/**
 * Called when server relpyes to addr.
 * A positive return value means the number of bytes that have been
 * sent on socket.
 * A negative return value means that an error has occured.
 */
size_t net_send(struct sockaddr_in* addr, socklen_t len, const char* buf, int length) {   

	size_t bytes_sent;

	if (!addr) {
		_ERR("No addr to send to");
	}

	bytes_sent = sendto(my_udp_socket, buf, length, 0,
			(struct sockaddr*) addr, len);

	if (bytes_sent < 0) {
		perror("sendto");
		return -1;
	}

	return bytes_sent;
}

