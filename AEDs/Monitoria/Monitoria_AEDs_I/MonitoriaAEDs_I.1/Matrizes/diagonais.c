#include <biblioteca_c.h>

void PrintMatriz(int size, int matriz[size][size]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%3d", matriz[i][j]);
		}
		printf("\n");
	}
}

void FillMatriz(int size, int matriz[size][size]) {
	int contador = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matriz[i][j] = contador++;
		}
	}
}

int main() {

	int size = 4;

	int matriz[size][size];

	FillMatriz(size, matriz);
	PrintMatriz(size, matriz);

	printf("\n---------- Printando Diagonal Principal ---------\n");

	for (int i = 0; i < size; i++) {
		printf("%d ", matriz[i][i]);
	}

	printf("\n---------- Printando Diagonal Secundaria ---------\n");

	for (int i = 0; i < size; i++) {
		printf("%d ", matriz[i][size - i - 1]);
	}

	printf("\n---------- Printando acima Da Diag Principal ---------\n");

	for (int i = 0; i < size; i++) {
		for (int j = 1 + i; j < size; j++) {
			printf("%d ", matriz[i][j]);
		}
	}

	printf("\n---------- Printando abaixo Da Diag Principal ---------\n");

	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			printf("%d ", matriz[i][j]);
		}
	}

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}