#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "mouse.h"
#include "cg2d.h"

/*
Atividade 1 de computacao grafica
Alunos:
	Pedro Vinicius Gallo Menegasso	RA 595160
	Rafael Bordin					RA xxxxxx
*/

#define MAX_POINTS 100


int * NormalizaVetor(signed char list[], int size){
	// Cria novo vetor para resultado
	int * newVector = (int *) malloc(size*sizeof(int));
	
	// Inicializa o vetor
	newVector[0] = list[0];
	
	// Percorre o vetor:
	
	for(int i = 1; i<size; i++){

		newVector[i] = newVector[i-1]+list[i];

	}
}


int main(void) {

	// Variaveis relacionadas ao ambiente grafico
	palette * palheta;
	bufferdevice * monitor;
	window * janela;
	viewport * porta;
	object * desenho;
	
	
	SetWorld(-20, -20, 10, 15); // Define o tamanho do mundo  
	monitor = CreateBuffer(640,480); // Cria um monitor virtual
  
	palheta = CreatePalette(5);  // Cria um colormap (lookup table) com 5 cores
	SetColor(0,0,0,palheta);
	SetColor(1,0,0,palheta);
	SetColor(0,1,0,palheta);
	SetColor(0,0,1,palheta);

	desenho = CreateObject(MAX_POINTS); // cria um objeto correspondente aos pontos

	// Variaveis relacionadas ao mouse input
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
	xList[0] = 0;
	yList[0] = 0;
	while (!clique) {
		clique = esquerdoApertado(fd);
		xy = coordenadasMouse(fd);
		//Insere novos pontos apenas se o ponteiro do mouse mexer
		signed char new_x = xy[0];
		signed char new_y = xy[1];
		if(new_x != xList[count] || new_y != yList[count]){
			xList[count] = xy[0];
			yList[count] = xy[1];
			count ++;
		}
		//Limita ao tamanho máximo do array
		if (count == MAX_POINTS){
			free(xy);
			break;
		}
	}

	// Agora transformamos os pontos em retas e utilizamos o primeiro ponto como a origem. os
	// proxs pontos serao "absolutos" em relacao a esta origem
	/*

	X0 = [n0], X1 = [n0+n1], X2 = [n0+n1+n2]

	Y0 = [n0], Y1 = [n0+n1], Y2 = [n0+n1+n2]

	*/


	for(int i = 0; i<count; i++){
		printf("X%d = %d  ", i, xList[i]);
		printf("Y%d = %d\n", i, yList[i]);
	}

	int * novoX;
	int * novoY;
	novoX = NormalizaVetor(xList, MAX_POINTS);
	novoY = NormalizaVetor(xList, MAX_POINTS);


	free(novoX);
	free(novoY);

		

}



