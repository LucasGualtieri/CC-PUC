#include <stdio.h>
#include <stdlib.h>

// clear && gcc solitario.c && ./a.out < pub.in

int readInt() {
	int integer;
	if (scanf("%d", &integer) == EOF) return 0;
	getchar();
	return integer;
}

void IntArrayPrint(int* array, int n) {
	printf("{ ");
	for (int i = 0; i < n; i++) {
		printf("%d", array[i]);
		printf("%s", i < n - 1 ? ", " : " }\n");
	}
}

void selectionSort(int* array, int n) {
	for (int i = 0; i < n - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < n; j++) {
			if (array[menor] > array[j]) menor = j;
		}
		int swap = array[menor];
		array[menor] = array[i];
		array[i]	 = swap;
	}
}

void InsertionSort(int* array, int size) {
	int j, temp;
	for (int i = 1; i < size; i++) {
		temp = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > temp) {
			array[j + 1] = array[j--];
		}
		array[j + 1] = temp;
		IntArrayPrint(array, size);
	}
}

int numeroSemPar(int* array, int n) {
	int resultado;
	for (int i = 0; i < n; i += 2) {
		if (i < n - 1 && array[i] != array[i + 1]) {
			// printf("IF\n");
			// printf("I: %d\n", i);
			// printf("array[%d]: %d\n", i, array[i]);
			// printf("array[%d]: %d\n", i + 1, array[i + 1]);
			resultado = array[i];
			i = n;
		} else if (i == n - 1) {
			// printf("ELSE IF\n");
			// printf("I: %d\n", i);
			// printf("array[%d]: %d\n", i, array[i]);
			// printf("array[%d]: %d\n", i + 1, array[i + 1]);
			resultado = array[i];
		}
	}
	return resultado;
}

int main() {
	
	int *array, arraySize;

	while ((arraySize = readInt()) != 0) {
		// printf("arraySize: %d\n", arraySize);

		array = (int*)malloc(arraySize * sizeof(int));

		for (int i = 0; i < arraySize; i++) {
			array[i] = readInt();
			// printf("array[i]: %d\n", array[i]);
			// lista.InserirOrdenado();
		}

		// IntArrayPrint(array, arraySize);
		// selectionSort(array, arraySize);
		InsertionSort(array, arraySize);
		// IntArrayPrint(array, arraySize);
		// exit(0);

		printf("%d\n", numeroSemPar(array, arraySize));

		free(array);
		// exit(0);
	}

	return 0;
}