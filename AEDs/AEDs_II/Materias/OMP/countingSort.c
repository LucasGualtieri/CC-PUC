#include <stdio.h>
#include "AuxLibs/IntArray.h"

// clear && gcc countingSort.c && ./a.out

void CountingSort(IntArray array) {

	int* buffer = array.array;
	int	N = array.size;

	int maxValue = buffer[0];

	for (int i = 0; i < N; i++) {
		if (buffer[i] > maxValue) maxValue = buffer[i];
	}

	int* auxArray = (int*)calloc(maxValue, sizeof(int));

	for (int i = 0; i < N; i++) {
		auxArray[buffer[i]]++;
	}

	int i = 0, j = 0;
	while (i < N) {
		if (auxArray[j] == 0) j++;
		else {
			buffer[i++] = j;
			auxArray[j]--;
		}
	}
}

int main() {

	IntArray arrayDeIdades = newIntArray(10); // 1 Bilhão

	// array.FillOrdered(10, 1, array);
	arrayDeIdades.FillRand(0, 100, arrayDeIdades);
	arrayDeIdades.Print(arrayDeIdades);

	CountingSort(arrayDeIdades);
	arrayDeIdades.Print(arrayDeIdades);

	arrayDeIdades.Close(arrayDeIdades);

	printf("Fim da Ordenação\n");

}