#include <stdio.h>
#include "IntArray.h"

// clear && gcc insertionSortBinarySearchSearch.c && ./a.out

int BinarySearchRec(int x, int* array, int left, int right) {
	int pivot = (left + right) / 2;
	int pivotValue = array[pivot];

	if (left >= right) {
		return pivotValue <= x ? pivot + 1 : pivot;
	}
	
	if (pivotValue < x) left = pivot + 1;
	else right = pivotValue - 1;

	return BinarySearchRec(x, array, left, right);
}

int BinarySearch(int x, int* array, int right) {

	int	left = 0, pivotValue, pivot = 0;
	while (left < right) {
		pivot = (left + right) / 2;
		pivotValue = array[pivot];
		if (pivotValue) left = pivotValue + 1;
		else right = pivotValue - 1;
	}
	
	return pivotValue <= x ? pivot + 1 : pivot;
}

void InsertionSort(IntArray array) {
	int size = array.size;
	int* buffer = array.array;

	int tmp, shiftIndex;
	for (int i = 1; i < size; i++) {
		tmp = buffer[i];
		shiftIndex = BinarySearch(tmp, buffer, i - 1);
		printf("shiftIndex: %d\n", shiftIndex);
		for (int j = i; j > shiftIndex; j--) {
			buffer[j] = buffer[j - 1];
		}
		buffer[shiftIndex] = tmp;
	}
}

int main() {

	IntArray array = newIntArray(10);

	// array.FillRand(-50, 50, array);
	array.FillOrdered(0, 50, array);
	array.Print(array);

	InsertionSort(array);
	array.Print(array);

	array.Close(array);

}