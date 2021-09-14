# define o compilador
CC=gcc
# define flags do ambiente grafico
FLAGS = -lm -lX11

default: pratica1

pratica1: atividade1.c cg2d.o mouse.o bibaux.o
	$(CC) atividade1.c cg2d.o mouse.o bibaux.o $(FLAGS) 

mouse.o: mouse.c mouse.h
	$(CC) -c mouse.c

cg2d.o: cg2d.c 
	$(CC) -c cg2d.c

clean:
	$(RM) cg2d.o mouse.o pratica1.o a.out
