#include <stdio.h>
#include "../AuxLibs/IntArray.h"

// clear && gcc mergeSortTradicional.c && ./a.out

void arrayPrint(int* array, int size) {
	printf("{ ");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("}\n");
}

void intercalar(int* array, int left, int meio, int right) {
	
	printf("---- Intercalar ----\n");

	printf("left: %d ", left);
	printf("meio: %d ", meio);
	printf("right: %d\n", right);

	if (right - left == 1) {
		printf("RETORNANDO\n");
		return;
	}

	int n1, n2, i, j, k;

	// meio++; // Ou meio + 1

	//Definir tamanho dos dois subarrays
	// n1 = meio - left + 1;

	int auxSize = (right - left) + 1;
	int* aux = (int*)malloc(auxSize * sizeof(int)); 

	for (i = left; i <= right; i++) { aux[i] = array[i]; }
	// for (j = 0; j < n2; j++) { a2[j] = array[meio + j + 1]; }

	//Sentinela no final dos dois arrays
	// aux[i] = 0x7FFFFFFF;

	// //Intercalacao propriamente dita
	// for (i = j = 0, k = left; k <= right; k++){
	// 	array[k] = (aux[i] <= a2[j]) ? aux[i++] : a2[j++];
	// }

	printf("aux: ");
	arrayPrint(aux, auxSize);
	// printf("teste\n");
	i = left, j = meio + 1;
	while (i <= meio && meio <= right) {
		if (aux[i] <= aux[j]) {
			array[left++] = aux[i++];
		} else {
			array[left++] = aux[j++];
		}
	}
	printf("array: ");
	arrayPrint(array, auxSize);

	free(aux);

	// exit(0);
}

void mergesortRec(int *array, int left, int right) {
	if (left < right){
		int mid = (left + right) / 2;
		printf("Esquerda:\n");
		mergesortRec(array, left, mid);
		printf("Direita:\n");
		mergesortRec(array, mid + 1, right);
		intercalar(array, left, mid, right);
	}
}

void mergesort(IntArray array) {
	mergesortRec(array.array, 0, array.size);
}


void main() {

	IntArray array = newIntArray(8);
	
	IntArrayFillRand(0, 50, array);
	IntArrayPrint(array);

	mergesort(array);
	IntArrayPrint(array);

}