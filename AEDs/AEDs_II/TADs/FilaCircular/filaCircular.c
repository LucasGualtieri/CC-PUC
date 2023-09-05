#include <stdio.h>
#include <stdlib.h>
#include "filaCircular.h"

// clear && gcc -o filaCircular filaCircular.c && ./filaCircular

int main () {

	puts("---- LISTA CIRCULAR ----\n");

	FilaCircular fila = newFilaCircular(5);

	fila.ToggleShow(&fila);

	fila.Inserir(1, &fila);
	fila.Inserir(7, &fila);
	fila.Inserir(9, &fila);
	fila.Inserir(3, &fila);
	// fila.Mostrar(fila);

    int x1, x2, x3;
    
    x1 = fila.Next(&fila);
    x2 = fila.Next(&fila);
    x3 = fila.Next(&fila);
    
    // printf("%d, %d, %d\n", x1, x2, x3);
    
	// fila.Mostrar(fila);

	fila.Close(&fila);
}