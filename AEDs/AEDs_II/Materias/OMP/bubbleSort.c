#include <stdio.h>
#include "AuxLibs/IntArray.h"

// clear && gcc bubbleSort.c && ./a.out

// Faster without function?
void swap(int* var1, int* var2) {
	int aux = *var1;
	*var1 = *var2;
	*var2 = aux;
}

// void BubbleSort(IntArray array) { // Otimizado

// 	int* buffer = array.array;
// 	int N = array.size;

// 	int j;
// 	for (int i = (N - 1); i > 0; i--) {
// 		for (j = 0; j < i; j++) {
// 			if (buffer[j] > buffer[j + 1]) {
// 				swap(&buffer[j], &buffer[j + 1]);
// 			}
// 		}
// 	}
// }

void BubbleSort(IntArray array) {

	int* buffer = array.array;
	int N = array.size;

	int j;
	for (int i = 0; i < N - 1; i++) {
		for (j = 0; j < N - 1; j++) {
			if (buffer[j] > buffer[j + 1]) {
				swap(&buffer[j], &buffer[j + 1]);
			}
		}
	}
}

int main() {

	IntArray array = newIntArray(10);

	// array.FillOrdered(10, 1, array);
	array.FillRand(-50, 50, array);
	array.Print(array);

	BubbleSort(array);
	array.Print(array);

	array.Close(array);

}