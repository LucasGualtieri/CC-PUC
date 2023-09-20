#include <stdio.h>
#include <stdlib.h>
#include "listaLinear.h"

// clear && gcc listaLinear.c && ./a.out

void inverteLista(Lista* lista) {
	int* array = lista->array;
	int size = lista->size;

	for (int i = 0; i < size / 2; i++) {
		int aux = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = aux;
	}
}

int main () {

	puts("----- LISTA LINEAR -----\n");

	Lista lista = newLista(6);
	
	lista.ToggleShow(&lista);

	lista.Mostrar(lista);
	lista.RemoverInicio(&lista);
	lista.InserirInicio(1, &lista);
	lista.InserirFim(7, &lista);
	lista.InserirFim(9, &lista);
	lista.InserirInicio(3, &lista);
	lista.Inserir(8, 3, &lista);
	lista.Inserir(4, 2, &lista);

	printf("---------------\n");

	int x1, x2, x3;

	x1 = lista.RemoverInicio(&lista);
	x2 = lista.RemoverFim(&lista);
	x3 = lista.Remover(2, &lista);

	printf("Números removidos: %d, %d, %d\n", x1, x2, x3);

	// lista.Mostrar(lista);

	printf("A lista invertida é:\n");
	inverteLista(&lista);
	lista.Mostrar(lista);

	lista.Close(&lista);

	lista.InserirInicio(1, &lista);
	lista.RemoverInicio(&lista);
}