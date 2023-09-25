#include <stdio.h>
#include "../AuxLibs/IntArray.h"

// clear && gcc mergeSortTradicional.c && ./a.out

void mergesort(IntArray array);

void mergesortRec(int *array, int left, int right);

void intercalar(int* array, int left, int mid, int right);

void main() {

	IntArray array = newIntArray(10);
	
	IntArrayFillRand(0, 50, array);
	IntArrayPrint(array);

	mergesort(array);
	IntArrayPrint(array);

}

void mergesort(IntArray array) {
	mergesortRec(array.array, 0, array.size - 1);
}

void mergesortRec(int *array, int left, int right){
	if (left < right){
		int mid = (left + right) / 2;
		mergesortRec(array, left, mid);
		mergesortRec(array, mid + 1, right);
		intercalar(array, left, mid, right);
	}
}

void intercalar(int* array, int left, int mid, int right){
	int n1, n2, i, j;

	//Definir tamanho dos dois subarrays
	n1 = mid - left + 1;
	n2 = right - mid;

	int* a1 = (int*)malloc((n1 + 1) * sizeof(int)); 
	int* a2 = (int*)malloc((n2 + 1) * sizeof(int));

	// Inicializar primeiro subarray
	for (i = 0; i < n1; i++) {
		a1[i] = array[left + i];
	}

	// Inicializar segundo subarray
	for (j = 0; j < n2; j++) {
		a2[j] = array[mid+j+1];
	}

	// Sentinela no final dos dois arrays
	a1[i] = a2[j] = 0x7FFFFFFF;

	//Intercalacao propriamente dita
	for (i = j = 0; left <= right; left++) {
		array[left] = (a1[i] <= a2[j]) ? a1[i++] : a2[j++];
	}
}