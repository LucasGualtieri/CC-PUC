#include <stdio.h>
#include <stdlib.h>
#include "pilhaLinear.h"

// clear && gcc pilhaLinear.c && ./a.out

int main () {

	puts("----- PILHA LINEAR -----\n");

	Pilha pilha = newPilha(6);
	
	pilha.ToggleShow(&pilha);

	pilha.Mostrar(pilha);
	pilha.Remover(&pilha);
	pilha.Inserir(1, &pilha);
	pilha.Inserir(7, &pilha);
	pilha.Inserir(9, &pilha);
	pilha.Inserir(3, &pilha);
	pilha.Inserir(8, &pilha);
	pilha.Inserir(4, &pilha);

	printf("---------------\n");

	int x1, x2, x3;

	x1 = pilha.Remover(&pilha);
	x2 = pilha.Remover(&pilha);
	x3 = pilha.Remover(&pilha);

	printf("Números removidos: %d, %d, %d\n", x1, x2, x3);

	// pilha.Mostrar(pilha);

	pilha.Close(&pilha);
	
	pilha.Inserir(1, &pilha);
	pilha.Remover(&pilha);
}