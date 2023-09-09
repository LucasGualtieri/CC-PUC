#include <stdio.h>
#include <string.h>
#include "IntArray.h"
#include "Timer.h"

// clear && gcc InsertionVsInsertion.c && ./a.out

int BinarySearch(int x, int* array, int right) {

	int	left = 0, pivotValue, pivot;
	do {
		pivot = (left + right) / 2;
		pivotValue = array[pivot];
		if (pivotValue < x) left = pivot + 1;
		else right = pivot - 1;
	} while (left <= right);
	
	return pivotValue <= x ? pivot + 1 : pivot;
}

void InsertionSortBinSearch(IntArray array) {
	int size = array.size;
	int* buffer = array.array;

	int tmp, shiftIndex;
	for (int i = 1; i < size; i++) {
		tmp = buffer[i];
		shiftIndex = BinarySearch(tmp, buffer, i - 1);
		for (int j = i; j > shiftIndex; j--) {
			buffer[j] = buffer[j - 1];
		}
		buffer[shiftIndex] = tmp;
	}
}

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

	int arraySize = 600000;

	IntArray array01 = newIntArray(arraySize);
	IntArray array02 = newIntArray(arraySize);

	array01.FillRand(-arraySize, arraySize, array01);
	memcpy(array02.array, array01.array, arraySize * sizeof(int));

	// array01.Print(array01);
	// array02.Print(array02);

	Timer timer = newTimer();

	timer.start(&timer);
	InsertionSortBinSearch(array02);
	printf("Result: %.3lfs\n", timer.stop(&timer));
	// array02.Print(array02);

	// timer.start(&timer);
	// InsertionSort(array01);
	// printf("Result: %.3lfs\n", timer.stop(&timer));
	// array01.Print(array01);

	array01.Close(array01);
	array02.Close(array02);
}