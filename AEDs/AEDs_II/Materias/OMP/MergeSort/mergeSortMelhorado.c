#include <stdio.h>
#include "../AuxLibs/IntArray.h"

// clear && gcc mergeSortMelhorado.c && ./a.out

void mergesort(IntArray array);

void mergesortRec(int *array, int left, int right);

void intercalar(int* array, int left, int mid, int right);

void main() {

	IntArray array = newIntArray(8);
	
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

	printf("Array inteiro:\n");
	for (int i = 0; i < 8; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	int leftOr = left;

	int auxSize = (right - left) + 1;

	int* aux = (int*)malloc(auxSize * sizeof(int)); 

	printf("left: %d\n", left);
	printf("mid: %d\n", mid);
	printf("right: %d\n", right);
	printf("auxSize: %d\n", auxSize);

	for (int i = 0; i < auxSize; i++) {
		// printf("Montand: %d ", array[left + i]);
		aux[i] = array[left + i];
	}
	// printf("\n");

	printf("Pós montar aux:\n");
	for (int i = 0; i < auxSize; i++) {
		printf("%d ", aux[i]);
	}
	printf("\n");
	int CE = 0, CD = (auxSize / 2);
	// printf("A CE: %d\n", CE);
	// printf("A CD: %d\n", CD);
	// printf("V CE: %d\n", aux[CE]);
	// printf("V CD: %d\n", aux[CD]);
	while (left <= right) {
		// printf("Looping...\n");
		// printf("CE: %d\n", CE);
		// printf("CD: %d\n", CD);
		if (CE <= mid || CD <= right) {
			array[left++] = (aux[CE] < aux[CD]) ? aux[CE++] : aux[CD++];
		} else {
			// array[left++] = (CE <= mid) ? aux[CE++] : aux[CD++];
			if (CE <= mid) {
				printf("CE <= mid\n");
				printf("array[%d] = aux[%d]\n", left, CE);
				array[left++] = aux[CE++];
			} else {
				printf("CD <= right\n");
				printf("array[%d] = aux[%d]\n", left, CD);
				array[left++] = aux[CD++];
			}
		}
		// printf("CE - 1: %d\n", CE - 1);
		// printf("CE: %d\n", CE);
		// printf("CD - 1: %d\n", CD - 1);
		// printf("CD: %d\n", CD);
		// printf("aux[CE - 1]: %d\n", aux[CE - 1]);
		// printf("aux[CE]: %d\n", aux[CE]);
		// printf("aux[CD - 1]: %d\n", aux[CD - 1]);
		// printf("aux[CD]: %d\n", aux[CD]);
	}
	
	printf("Pós intercalação:\n");
	for (int i = 0; i < auxSize; i++) {
		printf("%d ", array[i + leftOr]);
	}
	printf("\n-------------\n");
}