#include <stdio.h>
#include <stdlib.h>

// clear && gcc solitarioTeste.c && ./a.out < pub.in > result.txt

int readInt() {
	int integer = 0;
	scanf("%d", &integer);
	// getchar();
	return integer;
}

void IntArrayPrint(int* array, int n) {
	printf("{ ");
	for (int i = 0; i < n; i++) {
		printf("%d", array[i]);
		printf("%s", i < n - 1 ? ", " : " }\n");
	}
}

int J(int j) {
	printf("J: %d\n", j);
	return j;
}

void InsertionSort(int* array, int size) {
	int j, temp;
	for (int i = 1; i < size; i++) {
		temp = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > temp) {
			printf("J Pré: %d -> ", j);
			array[J(j + 1)] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
}

int numeroSemPar(int* array, int n) {
	int resultado = 0;
	for (int i = 0; i < n; i += 2) {
		if (i < n - 1 && array[i] != array[i + 1]) {
			i = n;
		} else if (i == n - 1) {
			resultado = array[i];
		}
	}
	return resultado;
}

int main() {
	
	int *array, arraySize;

	while ((arraySize = readInt()) != 0) {

		array = (int*)malloc(arraySize * sizeof(int));

		for (int i = 0; i < arraySize; i++) {
			array[i] = readInt();
			// lista.InserirOrdenado();
		}

		InsertionSort(array, arraySize);
		// IntArrayPrint(array, arraySize);

		printf("%d\n", numeroSemPar(array, arraySize));

		free(array);
	}

	return 0;
}