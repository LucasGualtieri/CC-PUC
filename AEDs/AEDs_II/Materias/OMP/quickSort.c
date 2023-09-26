#include <stdio.h>
#include "AuxLibs/IntArray.h"

// clear && gcc quickSort.c && ./a.out

void swap(int* var1, int* var2) {
	int aux = *var1;
	*var1 = *var2;
	*var2 = aux;
}

void QuickSortRec(int *array, int left, int right) {
	int i = left, j = right;
	int pivo = array[(right + left) / 2];
	while (i <= j) {
		while (array[i] < pivo) i++;
		while (array[j] > pivo) j--;
		if (i <= j) swap(&array[i++], &array[j--]);
	}
	if (left < j)  QuickSortRec(array, left, j);
	if (i < right)  QuickSortRec(array, i, right);
}

void QuickSort(IntArray array) {
    QuickSortRec(array.array, 0, array.size - 1);
}

int main() {

	IntArray array = newIntArray(10);

	// array.FillOrdered(10, 1, array);
	array.FillRand(-50, 50, array);
	array.Print(array);

	QuickSort(array);
	array.Print(array);

	array.Close(array);

}