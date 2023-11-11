#include <stdio.h>
#include "AuxLibs/IntArray.h"

// clear && gcc heapSort.c && ./a.out

void swap(int* var1, int* var2) {
	int aux = *var1;
	*var1 = *var2;
	*var2 = aux;
}

void buildMaxHeap(int root, int N, IntArray intArray) {

	int* array = intArray.array;

	int largest = root, l = 2 * root + 1, r = 2 * root + 2;

	if (l < N && array[l] > array[largest]) largest = l;
	if (r < N && array[r] > array[largest]) largest = r;

	if (largest != root) {
		swap(&array[root], &array[largest]);
		buildMaxHeap(largest, N, intArray);
	}
}

void HeapSort(IntArray intArray) {

	int N = intArray.size;
	int* array = intArray.array;

	for (int i = N / 2 - 1; i >= 0; i--) {
		buildMaxHeap(i, N, intArray);
	}

	for (int i = N - 1; i > 0; i--) {
		swap(&array[0], &array[i]);
		buildMaxHeap(0, i, intArray);
	}

}

void HeapSortParcial(int k, IntArray intArray) {

    int N = intArray.size;
    int* array = intArray.array;

    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--) {
        buildMaxHeap(i, N, intArray);
    }

    // Sort only the top K elements
    for (int i = N - 1; i > N - k - 1; i--) {
        swap(&array[0], &array[i]);
        buildMaxHeap(0, i, intArray);
    }
}

int main() {

	IntArray array = newIntArray(8);

	// array.FillOrdered(10, 1, array);
	array.FillRand(0, 50, array);
	array.Print(array);

	int k = 3;

	// HeapSort(array);
	HeapSortParcial(k, array);
	// array.Print(array);
	array.PrintParcial(k, array);

	array.Close(array);

}