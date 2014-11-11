#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "network.h"
#include "irq.h"

int main(int argc, char* argv[]) {
  	int	local_port = 3950;
	net_init(local_port);
	
	handle_events();

    return 1;
}
