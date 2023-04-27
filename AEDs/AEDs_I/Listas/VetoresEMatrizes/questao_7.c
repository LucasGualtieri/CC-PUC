#include <biblioteca_c.h>

void MatrixFillRand(int row, int col, int matrix[row][col], int minRange, int maxRange) {

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

void IntMatrixPrint(int row, int col, int matrix[row][col]) {
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

void FirstProcedure(int row, int col, int matrix[row][col]) {
	for (int i = 0; i < col; i++) {
		matrix[1][i] += matrix[7][i];
		matrix[7][i] = matrix[1][i] - matrix[7][i];
		matrix[1][i] -= matrix[7][i];
	}
}

void SecondProcedure(int row, int col, int matrix[row][col]) {
	for (int i = 0; i < col; i++) {
		matrix[i][3] += matrix[i][9];
		matrix[i][9] = matrix[i][3] - matrix[i][9];
		matrix[i][3] -= matrix[i][9];
	}
}

void ThirdProcedure(int row, int col, int matrix[row][col]) {
	for (int dp = 0, ds = col - 1; dp < 10; dp++, ds--) {
		matrix[dp][dp] += matrix[dp][ds];
		matrix[dp][ds] = matrix[dp][dp] - matrix[dp][ds];
		matrix[dp][dp] -= matrix[dp][ds];
	}
}

void FourthProcedure(int row, int col, int matrix[row][col]) {
	for (int i = 0; i < col; i++) {
		matrix[4][i] += matrix[i][9];
		matrix[i][9] = matrix[4][i] - matrix[i][9];
		matrix[4][i] -= matrix[i][9];
	}
}

int main() {

	int col = 10, row = col;
	int matrix[row][col];

	MatrixFillRand(row, col, matrix, 10, 50);
	IntMatrixPrint(row, col, matrix);

	printf("\n");

	FirstProcedure(row, col, matrix);
	IntMatrixPrint(row, col, matrix);

	printf("\n");

	SecondProcedure(row, col, matrix);
	IntMatrixPrint(row, col, matrix);

	printf("\n");

	ThirdProcedure(row, col, matrix);
	IntMatrixPrint(row, col, matrix);

	printf("\n");

	FourthProcedure(row, col, matrix);
	IntMatrixPrint(row, col, matrix);

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}