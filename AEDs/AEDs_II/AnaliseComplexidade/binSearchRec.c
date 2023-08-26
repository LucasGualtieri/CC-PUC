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

void swap(int* value1, int* value2) {
	int aux = *value1;
	*value1 = *value2;
	*value2 = aux;
}

void quicksortRec(int* array, int esq, int dir) {
    int i = esq, j = dir;
    int pivo = array[(dir+esq)/2];
    while (i <= j) {
        while (array[i] < pivo) i++;
        while (array[j] > pivo) j--;
        if (i <= j) {
            swap(array + i, array + j);
            i++;
            j--;
        }
    }
    if (esq < j)  quicksortRec(array, esq, j);
    if (i < dir)  quicksortRec(array, i, dir);
}

void quicksort(int* array, int n) {
    quicksortRec(array, 0, n-1);
}

void selectionsort(int* array, int n) {
	for (int i = 0; i < n - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < n; j++) {
			if (array[menor] > array[j]) menor = j;
		}
		// swap(array + i, array + menor);
	}
}

int main() {

	long int tam = 1000000000;
	int* array = (int*)malloc(tam * sizeof(int));

	printf("Preenchendo o array\n");

	for (int i = 0; i < tam; i++) {
		array[i] = i + 1;
	}

	printf("Ordenando o array\n");
	quicksort(array, tam);
	// selectionsort(array, tam);

	printf("%d%s pertence ao array.\n", 23244, bin(23244, array, tam) ? "" : " não");

	// for (int i = -1000000; i <= tam + 1000000; i+=100000) {
	// 	printf("%d%s pertence ao array.\n", i, bin(i, array, tam) ? "" : " não");
	// }

	printf("FIM DO PROGRAMA\n");
	free(array);
}
