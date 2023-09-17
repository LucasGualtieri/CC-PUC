#include <stdio.h>
#include <string.h>
#include "IntArray.h"
#include "Timer.h"

// clear && gcc InsertionVsInsertion.c && ./a.out

int BinarySearchRecAux(int x, int* array, int left, int right) {
	int pivot = (left + right) / 2;
	int pivotValue = array[pivot];

	if (left >= right) {
		return pivotValue <= x ? pivot + 1 : pivot;
	}
	
	if (pivotValue < x) left = pivot + 1;
	else right = pivot - 1;

	return BinarySearchRecAux(x, array, left, right);
}

int BinarySearchRec(int x, int* array, int right) {
	BinarySearchRecAux(x, array, 0, right);
}

int BinarySearchIte(int x, int* array, int right) {

	int	left = 0, pivotValue, pivot;
	do {
		pivot = (left + right) / 2;
		pivotValue = array[pivot];
		if (pivotValue < x) left = pivot + 1;
		else right = pivot - 1;
	} while (left <= right);
	
	return pivotValue <= x ? pivot + 1 : pivot;
}

void InsertionSortBinSearchIte(IntArray array) {
	int size = array.size;
	int* buffer = array.array;

	int tmp, shiftIndex;
	for (int i = 1; i < size; i++) {
		tmp = buffer[i];
		shiftIndex = BinarySearchIte(tmp, buffer, i - 1);
		for (int j = i; j > shiftIndex; j--) {
			buffer[j] = buffer[j - 1];
		}
		buffer[shiftIndex] = tmp;
	}
}

void InsertionSortBinSearchRec(IntArray array) {
	int size = array.size;
	int* buffer = array.array;

	int tmp, shiftIndex;
	for (int i = 1; i < size; i++) {
		tmp = buffer[i];
		shiftIndex = BinarySearchRec(tmp, buffer, i - 1);
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
		j = i - 1;
		while (j >= 0 && buffer[j] > temp) {
			buffer[j + 1] = buffer[j];
			j--;
		}
		buffer[j + 1] = temp;
	}
}

int main() {

	int arraySize = 100000;

	IntArray array01 = newIntArray(arraySize);
	IntArray array02 = newIntArray(arraySize);
	IntArray array03 = newIntArray(arraySize);

	// array01.FillRand(-arraySize, arraySize, array01);
	array01.FillOrdered(arraySize, 1, array01);
	memcpy(array02.array, array01.array, arraySize * sizeof(int));
	memcpy(array03.array, array01.array, arraySize * sizeof(int));

	// array01.Print(array01);
	// array02.Print(array02);
	// array03.Print(array03);

	Timer timer = newTimer();

	timer.Start(&timer);
	InsertionSortBinSearchIte(array01);
	printf("Binary Search Iterative: %.3lfs\n", timer.Stop(&timer));
	// array02.Print(array02);
	
	timer.Start(&timer);
	InsertionSortBinSearchRec(array02);
	printf("Binary Search Recursive: %.3lfs\n", timer.Stop(&timer));
	// array02.Print(array02);

	timer.Start(&timer);
	InsertionSort(array03);
	printf("Normal: %.3lfs\n", timer.Stop(&timer));
	// array01.Print(array01);

	array01.Close(array01);
	array02.Close(array02);
}