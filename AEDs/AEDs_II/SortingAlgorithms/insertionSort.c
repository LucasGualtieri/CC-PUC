#include <stdio.h>
#include "IntArray.h"

// clear && gcc insertionSort.c && ./a.out

void InsertionSort(IntArray array) {
	int size = array.size;
	int* buffer = array.array;

	int j, temp;
	for (int i = 1; i < size; i++) {
		temp = buffer[i];
		for (j = i - 1; j >= 0 && buffer[j] > temp; j--) {
			buffer[j + 1] = buffer[j];
		}
		buffer[j + 1] = temp;
	}

}

int main() {

	// IntArray array = newIntArray(5);

	// array.FillOrdered(10, 1, array);
	array.FillRand(-50, 50, array);
	array.Print(array);

	InsertionSort(array);
	array.Print(array);

	array.Close(array);

}