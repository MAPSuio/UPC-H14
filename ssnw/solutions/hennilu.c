// @EXPECTED_RESULTS@: CORRECT
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

static int udp_socket = 0;
static int BUF_SIZ = 256;
static int PORT = 3950;

void net_init() 
{
	udp_socket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if(udp_socket < 0) {
        perror("socket()");
		exit(-1);
	}
}

void net_send()
{
    struct sockaddr_in addr;
    struct hostent host;
    int retval;
    char msg[256];
    int msg_size;

    /*
	memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_family      = AF_INET;
	//addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_addr.s_addr = inet_addr("178.62.248.162");
	addr.sin_port        = htons(PORT);
    */
	struct hostent* host_entry_ptr;
	struct sockaddr_in dest_addr;

	dest_addr.sin_family = AF_INET;
	//host_entry_ptr = gethostbyname("localhost");
	//host_entry_ptr = gethostbyname("vor.ifi.uio.no");
	host_entry_ptr = gethostbyname("10.133.234.216");

	memcpy((char*) &(dest_addr.sin_addr.s_addr), host_entry_ptr->h_addr_list[0],
		host_entry_ptr->h_length);

	dest_addr.sin_port = htons(3950);

    msg_size = create_message(msg);

    retval = sendto(udp_socket, msg, msg_size, 0, (struct sockaddr*)&dest_addr,
			sizeof(dest_addr));

    if (retval == -1) {
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
		perror("recvfrom()");
        exit(-1);
	} 

    int answer = 

    printf("%s\n", &buffer[sizeof(uint8_t) * 4]);
}

int create_message(char* msg)
{
    /* Data types */
    uint8_t length;
    uint8_t type;
    uint8_t input1;
    uint8_t input2;
    uint32_t test1;
    uint32_t test2;

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
    scanf("%hhd", &input1);
    scanf("%hhd", &input2);

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
