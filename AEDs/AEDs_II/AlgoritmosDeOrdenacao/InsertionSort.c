// #include <array.h>
// #include <biblioteca_c.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define OR ||

void ArrayPrint(int* vetor, int size) {
	printf("{ ");
	for (int i = 0; i < size; i++) {
		printf("%d", vetor[i]);
		printf("%s", i < size - 1 ? ", " : " }\n");
	}
}

void InsertionSort(int* array, int size) {
	for (int i = 1; i < size; i++) { // i = First Unsorted
		if (array[i - 1] > array[i]) {
			int swap = i;
			int temp = array[swap];
			for (int j = i - 1; j >= 0 && array[j] > temp; j--) {
				// Shifting to the right
				array[j + 1] = array[j];
				ArrayPrint(array, size);
				swap = j;
			}
			array[swap] = temp;
			ArrayPrint(array, size);
		}
	}
}

int main() {

	// Array* array = NewArray(10);
	// ArrayFillRand(array, -2, 2);

	int vetor[] = { 6, 1, 7, 4 };
	ArrayPrint(vetor, 4);

	// InsertionSort(array->pointer, array->size - 1);
	InsertionSort(vetor, 4);

	ArrayPrint(vetor, 4);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}