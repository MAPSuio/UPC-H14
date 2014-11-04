#!/bin/bash
gcc -O3 -Wall -Wextra -Werror -march=native hawken.c -o hawken
strip hawken
gcc -O3 -Wall -Wextra -Werror -march=native -lz cdedup.c -o cdedup
strip cdedup
