#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filaCircularSD.h"

// clear && gcc filaCircularSD.c && ./a.out

int main() {

	puts("---- LISTA CIRCULAR ----\n");

	FilaCircular fila = newFilaCircular(5);

	fila.ToggleShow(&fila);

	fila.Inserir(1, &fila);
	fila.Inserir(2, &fila);
	fila.Inserir(3, &fila);
	fila.Inserir(4, &fila);
	fila.Inserir(5, &fila);
	fila.Remover(&fila);
	fila.Remover(&fila);
	fila.Remover(&fila);
	fila.Remover(&fila);
	fila.Remover(&fila);

	fila.Close(&fila);
}