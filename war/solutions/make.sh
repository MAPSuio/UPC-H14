#!/bin/bash

javac hawken.java

gcc -O3 -Wall -Wextra -Werror -march=native hawken.c -o hawken
