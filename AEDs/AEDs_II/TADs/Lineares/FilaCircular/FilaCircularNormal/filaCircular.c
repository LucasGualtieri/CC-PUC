#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filaCircular.h"

// clear && gcc filaCircular.c && ./a.out

// Funciona para filas ordenadas APENAS!!! SE E SOMENTE SE ORDENADAS
bool PesquisaBinaria(int elemento, FilaCircular fila) {
	int low = 0, high = fila.size - 1;
	bool resultado = false;

	int* array = fila.array;
	int first = fila.first;
	int size = fila.maxSize;

	while (low <= high) {
		int meio = (low + high) / 2;
		int elementoMeio = array[(first + meio) % size];

		if (elementoMeio == elemento) {
			resultado = true;
			low = high + 1;
		} else if (elementoMeio < elemento) {
			low = meio + 1;
		} else {
			high = meio - 1;
		}
	}

	return resultado;
}

int main () {

	puts("----- FILA CIRCULAR SEM DENTE -----\n");

	FilaCircular fila = newFilaCircular(6);
	
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

	int buscar = 7;
	bool resultado = PesquisaBinaria(buscar, fila);
	printf("'%d' %spertence à fila.\n", buscar, resultado ? "" : "não ");

	// fila.Mostrar(fila); 

	printf("---------------\n");

	int x1, x2, x3;

	x1 = fila.Remover(&fila);
	x2 = fila.Remover(&fila);
	x3 = fila.Remover(&fila);

	printf("Números removidos: %d, %d, %d\n", x1, x2, x3);

	printf("---------------\n");

	buscar = 7;
	resultado = PesquisaBinaria(buscar, fila);
	printf("'%d' %spertence à fila.\n", buscar, resultado ? "" : "não ");
	
	printf("---------------\n");

	// fila.Mostrar(fila);

	fila.Close(&fila);

	fila.Inserir(1, &fila);
	fila.Remover(&fila);
}