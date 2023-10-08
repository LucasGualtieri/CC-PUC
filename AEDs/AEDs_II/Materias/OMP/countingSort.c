#include <stdio.h>
#include "AuxLibs/IntArray.h"
#include "AuxLibs/Timer.h"

// clear && gcc countingSort.c && ./a.out

void CountingSort(IntArray array) {

	int* buffer = array.array;
	int	N = array.size;

	int maxValue = buffer[0];

	for (int i = 0; i < N; i++) {
		if (buffer[i] > maxValue) maxValue = buffer[i];
	}

	int* auxArray = (int*)calloc(maxValue + 1, sizeof(int));

	// int* auxArray = (int*)malloc(maxValue * sizeof(int));
	// for (int i = 0; i < maxValue; i++) auxArray[i] = 0; // If malloc'ing

	for (int i = 0; i < N; i++) auxArray[buffer[i]]++;

	int i = 0, j = 0;
	while (i < N) {
		if (auxArray[j] == 0) j++;
		else {
			buffer[i++] = j;
			auxArray[j]--;
		}
	}

	free(auxArray);
}

int main() {

	Timer timer = newTimer();
	IntArray array = newIntArray(1000000000); // 1 Bilhão

	timer.Start(&timer);
	// array.FillOrdered(0, 1000000000, array); // Preenche mais rápido
	array.FillRand(0, 100, array);
	printf("Tempo para preencher: %.3lfs\n", timer.Stop(&timer));
	// array.Print(array);

	timer.Start(&timer);
	CountingSort(array);
	printf("Tempo para ordenar: %.3lfs\n", timer.Stop(&timer));

	// array.Print(array);

	// array.Close(array);

}