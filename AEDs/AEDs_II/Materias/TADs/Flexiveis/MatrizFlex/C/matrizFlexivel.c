#include <stdio.h>
#include "matrizFlexivel.h"

// clear && gcc matrizFlexivel.c && ./a.out

int main() {

	puts("----- MATRIZ FLEXÍVEL -----\n");

	MatrizFlex matriz = newMatrizFlex(5, 5);
	matriz.Print(matriz);

	// matriz.ToggleShow(&matriz);

	// matriz.Mostrar(matriz);
	// matriz.Remover(&matriz);
	// matriz.Inserir(1, &matriz);
	// matriz.Inserir(7, &matriz);
	// matriz.Inserir(9, &matriz);
	// matriz.Inserir(3, &matriz);
	// matriz.Inserir(8, &matriz);
	// matriz.Inserir(4, &matriz);

	// printf("---------------\n");

	// int x1, x2, x3;

	// x1 = matriz.Remover(&matriz);
	// x2 = matriz.Remover(&matriz);
	// x3 = matriz.Remover(&matriz);

	// printf("Números removidos: %d, %d, %d\n", x1, x2, x3);

	// matriz.Mostrar(matriz);

	// matriz.Close(&matriz);
	
	// matriz.Inserir(1, &matriz);
	// matriz.Remover(&matriz);

	// matriz.Free(&matriz);

	return 0;
}