#include <stdio.h>
#include <stdlib.h>
#include "filaLinear.h"

// clear && gcc filaLinear.c && ./a.out

int main () {

	puts("----- FILA LINEAR -----\n");

	Fila fila = newFila(6);
	
	fila.ToggleShow(&fila);

	fila.Mostrar(fila);
	fila.Remover(&fila);
	fila.Inserir(1, &fila);
	fila.Inserir(7, &fila);
	fila.Inserir(9, &fila);
	fila.Inserir(3, &fila);
	fila.Inserir(8, &fila);
	fila.Inserir(4, &fila);

	printf("---------------\n");

	int x1, x2, x3;

	x1 = fila.Remover(&fila);
	x2 = fila.Remover(&fila);
	x3 = fila.Remover(&fila);

	printf("Números removidos: %d, %d, %d\n", x1, x2, x3);

	// fila.Mostrar(fila);

	fila.Close(&fila);

	fila.Inserir(1, &fila);
	fila.Remover(&fila);
}