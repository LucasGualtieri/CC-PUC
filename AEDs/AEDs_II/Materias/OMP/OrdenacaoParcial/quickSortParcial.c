#include <stdio.h>
#include "../AuxLibs/IntArray.h"

// clear && gcc quickSortParcial.c && ./a.out

// Faster without function?
void swap(int* var1, int* var2) {
	int aux = *var1;
	*var1 = *var2;
	*var2 = aux;
}

void QuickSortRec(int k, int *array, int left, int right) {
	int i = left, j = right;
	int pivo = array[(right + left) / 2];
	while (i <= j) {
		while (array[i] < pivo) i++;
		while (array[j] > pivo) j--;
		if (i <= j) swap(&array[i++], &array[j--]);
	}
	if (left < j) QuickSortRec(k, array, left, j);
	if (i < k && i < right) QuickSortRec(k, array, i, right);
}

void QuickSort(int k, IntArray array) {
    QuickSortRec(k, array.array, 0, array.size - 1);
}

int main() {

	IntArray array = newIntArray(7);

	// array.FillOrdered(10, 1, array);
	array.FillRand(1, 50, array);
	array.Print(array);

	int k = 3;
	QuickSort(k, array);
	array.Print(array);

	array.Close(array);

}