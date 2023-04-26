#include "/home/lucas/CC-PUC/Bibliotecas/biblioteca_c.h"

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

void ArrayFillRand(int* array1, int* array2, int arrayLength, int minRange, int maxRange) {

	srand(time(NULL));
	for (int i = 0; i < arrayLength; i++) {
		array1[i] = (rand() % ((maxRange + 1) - minRange)) + minRange;
		srand(rand());
	}
	for (int i = 0; i < arrayLength; i++) {
		array2[i] = (rand() % ((maxRange + 1) - minRange)) + minRange;
		srand(rand());
	}
}

void ArrayFill(int* array1, int* array2, int arrayLength) {
	int arrayDouble[2 * arrayLength];

	for (int i = 0, j = 0, k = 0; i < 20; i++) {
		if (i % 2 != 0) {
			arrayDouble[i] = array1[j];
			j++;
		} else {
			arrayDouble[i] = array2[k];
			k++;
		}
	}

	// printf("Size of arrayDouble: %d\n", arrayLength(arrayDouble));
	ArrayPrint(arrayDouble, arrayLength(arrayDouble));
}

int main() {

	int x[10], y[10];

	ArrayFillRand(x, y, arrayLength(x), 0, 50);
	IntVetorCrescente(x, arrayLength(x));
	IntVetorCrescente(y, arrayLength(y));
	ArrayPrint(x, arrayLength(x));
	ArrayPrint(y, arrayLength(y));

	ArrayFill(x, y, arrayLength(x));

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}