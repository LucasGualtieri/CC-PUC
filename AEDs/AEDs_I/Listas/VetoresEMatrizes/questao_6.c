#include <biblioteca_c.h>

int SumBelowMainDiagonal(int row, int col, int matrix[row][col]) {
	int soma = 0, li = 1, co = 0;
	while (co < col - 1) {
		if (co != li) {
			soma += matrix[li][co];
			co++;
		} else {
			co = 0;
			li++;
		}
	}
	return soma;
}

void IntMatrixPrint(int col, int row, int matrix[col][row]) {
	for (int i = 0; i < col; i++) {
		printf("%d { ", i);
		for (int j = 0; j < row; j++) {
			if (i == j) {
				printf("\e[1m%d!\e[m", matrix[i][j]);
			} else {
				printf("%d", matrix[i][j]);
			}

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

int main() {

	int col = 4, row = col;
	int matrix[row][col];

	MatrixFillRand(row, col, matrix, 10, 50);
	IntMatrixPrint(row, col, matrix);

	printf("Soma: %d\n", SumBelowMainDiagonal(row, col, matrix));

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}