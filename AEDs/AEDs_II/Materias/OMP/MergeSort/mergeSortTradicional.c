#include <stdio.h>
#include "../AuxLibs/IntArray.h"

// clear && gcc mergeSortTradicional.c && ./a.out

void MergeSort(IntArray array);

void MergeSortRec(int left, int right, int* array);

void Merge(int left, int mid, int right, int* array);

void main() {

	IntArray array = newIntArray(10);

	IntArrayFillRand(0, 50, array);
	IntArrayPrint(array);

	MergeSort(array);
	IntArrayPrint(array);

}

void MergeSort(IntArray array) {
	MergeSortRec(0, array.size - 1, array.array);
}

void MergeSortRec(int left, int right, int *array) {
	if (left < right){
		int mid = (left + right) / 2;
		MergeSortRec(left, mid, array);
		MergeSortRec(mid + 1, right, array);
		Merge(left, mid, right, array);
	}
}

void Merge(int* array, int left, int mid, int right) {
	int leftSize, rightSize, i, j;

	//Definir tamanho dos dois subarrays
	leftSize = mid - left + 1;
	rightSize = right - mid;

	int* aLeft = malloc((leftSize + 1) * sizeof(int)); 
	int* aRight = malloc((rightSize + 1) * sizeof(int));

	for (i = 0; i < leftSize; i++) aLeft[i] = array[left + i];
	for (j = 0; j < rightSize; j++) aRight[j] = array[mid + j + 1];

	aLeft[i] = aRight[j] = 0x7FFFFFFF;

	for (i = j = 0; left <= right; left++) {
		array[left] = aLeft[i] <= aRight[j] ? aLeft[i++] : aRight[j++];
	}

	free(aLeft);
	free(aRight);
}