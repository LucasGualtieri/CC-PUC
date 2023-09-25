#include <stdio.h>
#include "AuxLibs/IntArray.h"

// clear && gcc selectionSort.c && ./a.out

// Faster without function?
void swap(int* var1, int* var2) {
	int aux = *var1;
	*var1 = *var2;
	*var2 = aux;
}

void SelectionSort(IntArray array) {

	int* buffer = array.array;
	int	 N = array.size;

	for (int i = 0; i < N - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < N; j++) {
			if (buffer[menor] > buffer[j]) menor = j;
		}
		swap(&buffer[menor], &buffer[i]);
	}
}

int main() {

	IntArray array = newIntArray(10);

	// array.FillOrdered(10, 1, array);
	array.FillRand(-50, 50, array);
	array.Print(array);

	SelectionSort(array);
	array.Print(array);

	array.Close(array);

}