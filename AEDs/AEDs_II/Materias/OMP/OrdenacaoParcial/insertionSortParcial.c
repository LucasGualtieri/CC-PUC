#include <stdio.h>
#include "../AuxLibs/IntArray.h"

// clear && gcc insertionSortParcial.c && ./a.out

void InsertionSort(int k, IntArray array) {
	int size = array.size;
	int* buffer = array.array;

	int j, temp;
	for (int i = 1; i < size; i++) {
		temp = buffer[i];
		j = (i < k) ? i - 1 : k - 1;
		while (j >= 0 && buffer[j] > temp) {
			buffer[j-- + 1] = buffer[j];
		}
		buffer[j + 1] = temp;
	}
}

int main() {

	IntArray array = newIntArray(5);

	array.Fill(array, EOA, 38, 13, 23, 10, 47, EOA);
	array.Print(array);

	int k = 3;
	InsertionSort(k, array);
	array.Print(array);

	array.Close(array);

}