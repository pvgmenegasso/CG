#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "mouse.h"


// Abre o mouse e retorna o file descriptor
int openMouse() {
	// Abre o mouse
	int fd;
	if ((fd = open(MousePath, O_RDWR)) == -1) {
		printf("Houve um erro abrindo %s... você executou como superusuário?\n", MousePath);
		return -1;
		}
	return fd;
}

// Retorna 1 se botao esquerdo apertado, 0 senao
int esquerdoApertado(int mouse) {
	int bytes;
	int esquerdo;
	unsigned char data[3];
	bytes = read(mouse, data, sizeof(data));

	// Verifica se o botao esquerdo foi apertado
	esquerdo = data[0] & 0x1;

	if(esquerdo){
		return 1;
	}

	return 0;   
}

// Retorna um vetor signed char [2] com as coordenadas x e y do mouse
signed char* coordenadasMouse(int mouse) {

	signed char x, y;

	int bytes;

	unsigned char data[3];

	bytes = read(mouse, data, sizeof(data));

	

	x = data[1];
	y = data[2];

	signed char* coord = (signed char*) malloc(2*sizeof(signed char));

	coord[0] = x;
	coord[1] = y;

	return coord;

}
