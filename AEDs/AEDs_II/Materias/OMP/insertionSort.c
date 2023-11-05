#include <stdio.h>
#include "AuxLibs/IntArray.h"

// clear && gcc insertionSort.c && ./a.out

void InsertionSort(IntArray intArray) {

	int N = intArray.size;
	int* array = intArray.array;

	int j, temp;
	for (int i = 1; i < N; i++) {
		temp = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > temp) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
}

void PositiveInsertionSort(IntArray intArray) {

	int N = intArray.size;
	int* array = intArray.array;

	for (int i = 0; i < N; i++) {
		int tmp = array[i];
		int j = i - 1;
		while (j >= 0 && tmp >= 0 && (array[j] > tmp || array[j] < 0)) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = tmp;
	}
}

int main() {

	IntArray array = newIntArray(10);

	// array.FillOrdered(10, 1, array);
	array.FillRand(-50, 50, array);
	array.Print(array);

	InsertionSort(array);
	// PositiveInsertionSort(array);
	array.Print(array);

	printf("%sstá ordenado.\n", array.isSorted(array) ? "E" : "Não e");

	array.Close(array);

}