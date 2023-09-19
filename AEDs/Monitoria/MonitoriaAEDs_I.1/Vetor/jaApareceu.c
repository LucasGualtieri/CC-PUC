#include <biblioteca_c.h>

#define size 10

bool JaApareceu(int elemento, int* arrayAux) {
	for (int i = 0; i < size; i++) {
		if (arrayAux[i] == elemento) return true;
	}
	return false;
}

void PrintRepetidos(int* array) {
	int* arrayAux = (int*)calloc(size, sizeof(int));

	for (int i = 0; i < size; i++) {
		if (!JaApareceu(array[i], arrayAux)) {
			arrayAux[i] = array[i];
		} else {
			printf("%d", array[i]);
		}
	}
}

int main() {

	int array[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	PrintRepetidos(array);

	puts("\n\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}