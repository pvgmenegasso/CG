#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "mouse.h"
#include "cg2d.h"

#define MAX_POINTS 10000
int main(void) {

	signed char* xy;
	signed char xList[MAX_POINTS];
	signed char yList[MAX_POINTS];
	int count = 0;
    int fd;
	
    // Abre o mouse
    fd = openMouse();

    int clique = 0;
	

	// Loop para esperar clique esquerdo
	while (!clique) {
		clique = esquerdoApertado(fd);
	}

	// Se saiu do loop, houve um clique, armazena os proximos movimentos do mouse ate um novo clique
	clique = 0;

	while (!clique) {

		clique = esquerdoApertado(fd);

		xy = coordenadasMouse(fd);

		xList[count] = xy[0];
		yList[count] = xy[1];

		count ++;

		free(xy);
	}


	for(int i = 0; i<count; i++){
		printf("X%d = %d  ", i, xList[i]);
		printf("Y%d = %d\n", i, yList[i]);
	}

		

}