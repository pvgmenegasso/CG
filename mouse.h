#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MousePath "/dev/input/mice"


int openMouse();

int esquerdoApertado(int mouse);

signed char* coordenadasMouse(int mouse);