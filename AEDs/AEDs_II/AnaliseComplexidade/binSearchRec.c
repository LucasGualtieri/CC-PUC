#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define arraysize(array) (int)(sizeof(array) / sizeof(array[0]));

// bool binAux(int x, int* array, int esq, int dir) {
// 	bool hasFound = false;
// 	int meio = (esq + dir) / 2;
// 	int elementoBusca = array[meio];

// 	if (elementoBusca == x) hasFound = esq = dir + 1;
// 	else if (elementoBusca < x) esq = meio + 1;
// 	else dir = meio - 1;

// 	return esq <= dir && !hasFound ? binAux(x, array, esq, dir) : hasFound;
// }

bool binAux(int x, int* array, int esq, long int dir) {
	int meio = (esq + dir) / 2;
	int elementoBusca = array[meio];

	if (elementoBusca == x) return true;
	else if (elementoBusca < x) esq = meio + 1;
	else dir = meio - 1;

	return esq <= dir ? binAux(x, array, esq, dir) : false;
}

bool bin(int x, int* array, long int tam) {
	return binAux(x, array, 0, tam - 1);
}

int main() {

	long int tam = 1000000000;
	int* array = (int*)malloc(tam * sizeof(int));

	printf("Preenchendo o array\n");

	for (int i = 0; i < tam; i++) {
		array[i] = i + 1;
	}

	printf("%d%s pertence ao array.\n", 23244, bin(23244, array, tam) ? "" : " não");

	// for (int i = -1000000; i <= tam + 1000000; i+=100000) {
	// 	printf("%d%s pertence ao array.\n", i, bin(i, array, tam) ? "" : " não");
	// }

	printf("FIM DO PROGRAMA\n");
	free(array);
}
