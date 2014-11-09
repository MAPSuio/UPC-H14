#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "network.h"
#include "irq.h"

int main(int argc, char* argv[]) {
	int local_port;

  	/* listen port */
	local_port = 3950;

	net_init(local_port);

    /*
     * An endless loop for processing everything that happens on this server
     */

    handle_events();

    return 1;
}
