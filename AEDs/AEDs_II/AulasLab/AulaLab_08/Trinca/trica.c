#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ./trinca.exe < pub.in > out.txt

void scanningTheArray(int* array, int sizeOfArray) {
	for (int j = 0; j < sizeOfArray; j++) {
		scanf("%d", &array[j]);
	}
}

int printingRecurrence(int* array, int sizeOfArray) {
	int contador[100] = { 0 };
	int i, maior_repetido = -1;

	for (i = 0; i < sizeOfArray; i++) {
		contador[array[i]]++;
	}

	for (i = 0; i < sizeOfArray; i++) {
		if (contador[array[i]] >= 3 && (maior_repetido == -1 || array[i] > maior_repetido)) {
			maior_repetido = array[i];
		}
	}

	return maior_repetido;
}

int main() {

	int numeroDeTestes;
	scanf("%d", &numeroDeTestes);

	for (int i = 0; i < numeroDeTestes; i++) {
		int sizeOfArray;
		scanf("%d", &sizeOfArray);

		int* array = (int*)realloc(array, sizeOfArray * sizeof(int));

		scanningTheArray(array, sizeOfArray);

		printingRecurrence(array, sizeOfArray);

		free(array);
	}

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}