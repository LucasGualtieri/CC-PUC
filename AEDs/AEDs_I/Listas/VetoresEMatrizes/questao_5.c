#include <biblioteca_c.h>

void IntMatrixPrint(int col, int row, int matrix[col][row]) {
	for (int i = 0; i < col; i++) {
		printf("%d { ", i);
		for (int j = 0; j < row; j++) {
			printf("%d", matrix[i][j]);
			if (j == row - 1) {
				printf(" }\n");
				break;
			}
			printf(", ");
		}
	}
}

void MatrixFillRand(int col, int row, int matrix[col][row], int minRange, int maxRange) {

	srand(time(NULL));
	srand(rand());
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			matrix[i][j] = (rand() % ((maxRange + 1) - minRange)) + minRange;
			srand(rand());
			// printf("%d ", matrix[i][j]);
		}
	}
}

int SomaDaLinha4(int col, int row, int matrix[col][row]) {
	int soma = 0;
	for (int i = 0; i < row; i++) {
		soma += matrix[4][i];
	}
	return soma;
}

int SomaDaColuna2(int col, int row, int matrix[col][row]) {
	int soma = 0;
	for (int i = 0; i < row; i++) {
		soma += matrix[i][2];
	}
	return soma;
}

int SomaDiagonalPrincipal(int col, int row, int matrix[col][row]) {
	int soma = 0;
	for (int i = 0, j = 0; i < col; i++, j++) {
		soma += matrix[i][j];
	}
	return soma;
}

int SomaTodosElementos(int col, int row, int matrix[col][row]) {
	int soma = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			soma += matrix[i][j];
		}
	}
	return soma;
}

int main() {

	int row = 5, col = 5;
	int matrix[col][row];

	MatrixFillRand(col, row, matrix, 0, 50);
	IntMatrixPrint(col, row, matrix);

	printf("\n");

	printf("Soma da linha 4: %d\n", SomaDaLinha4(col, row, matrix));
	printf("Soma da coluna 2: %d\n", SomaDaColuna2(col, row, matrix));
	printf("Soma da diagonal principal: %d\n", SomaDiagonalPrincipal(col, row, matrix));
	printf("Soma de todos os elementos: %d\n", SomaTodosElementos(col, row, matrix));

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}