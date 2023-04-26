#include "/home/lucas/CC-PUC/Bibliotecas/biblioteca_c.h"

void ArrayFillRand(int* array, int arrayLength, int minRange, int maxRange) {

	srand(time(NULL));
	for (int i = 0; i < arrayLength; i++) {
		array[i] = (rand() % ((maxRange + 1) - minRange)) + minRange;
		srand(rand());
	}
}

void ArrayPrint(int* array, int arrayLength) {
	printf("{ ");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d", array[i]);
		if (i == arrayLength - 1) {
			printf(" }\n");
			break;
		}
		printf(", ");
	}
}

int* Metodo(int* array, int arrayLength, int* cont) {

	for (int i = 0; i < arrayLength; i++) {
		if (array[i] < 0) *cont = *cont + 1;
	}

	// int* arrayCopy = (int*)malloc(*cont * sizeof(int));
	int* arrayCopy = malloc(*cont * sizeof(int));

	for (int i = 0, j = 0; i < arrayLength; i++) {
		if (array[i] < 0) {
			arrayCopy[j] = array[i];
			j++;
		}
	}

	return arrayCopy;
}

int main() {

	int x[10], cont = 0;

	ArrayFillRand(x, arrayLength(x), -100, 100);
	IntVetorCrescente(x, arrayLength(x));
	IntArrayPrint(x, arrayLength(x));

	int* p = Metodo(x, arrayLength(x), &cont);

	ArrayPrint(p, cont);

	free(p);

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}