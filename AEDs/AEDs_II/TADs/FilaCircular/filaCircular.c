#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filaCircular.h"

// clear && gcc filaCircular.c && ./a.out

// Funciona para listas ordenadas APENAS!!! SE E SOMENTE SE ORDENADAS
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

	puts("---- LISTA CIRCULAR ----\n");

	FilaCircular fila = newFilaCircular(5);

	// fila.ToggleShow(&fila);

	fila.Inserir(1, &fila);
	fila.Inserir(3, &fila);
	fila.Inserir(7, &fila);
	fila.Inserir(9, &fila);
	// fila.Mostrar(fila);

	for (int i = 0; i < 15; i++) {
		bool teste = PesquisaBinaria(i, fila);
		printf("%d° Pesquisa Bin: %s\n", i, teste ? "ACHOU" : "NÃO ACHOU");
	}

    int x1, x2, x3;
    
    x1 = fila.Next(&fila);
    x2 = fila.Next(&fila);
    x3 = fila.Next(&fila);
    
    // printf("%d, %d, %d\n", x1, x2, x3);
	// fila.Mostrar(fila); 

	fila.Close(&fila);
}