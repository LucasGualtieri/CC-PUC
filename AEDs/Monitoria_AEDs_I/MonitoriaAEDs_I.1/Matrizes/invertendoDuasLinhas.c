#include <biblioteca_c.h>

#define MATRIX_SIZE 5

typedef struct Matrix {
	// matriz[ROWS][COLUMNS];
	int** pointer;
	int rows;
	int columns;
} Matrix;

// Helper Functions
void printMatriz(Matrix matrix);
void MatrixAllocation(Matrix* matrix, int rows, int columns);
void MatrixFillAscending(Matrix matrix);
void MatrixFree(Matrix matrix);

void MatrixInvert(int x, int y, Matrix matrix) {
	for (int i = 0; i < matrix.columns; i++) {
		int aux = matrix.pointer[x][i];
		matrix.pointer[x][i] = matrix.pointer[y][i];
		matrix.pointer[y][i] = aux;
	}
}

int main() {
	Matrix matrix;
	MatrixAllocation(&matrix, 3, 3);

	MatrixFillAscending(matrix);

	printMatriz(matrix);

	MatrixInvert(1, 2, matrix);

	printf("-----\n");

	printMatriz(matrix);

	MatrixFree(matrix);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}

void printMatriz(Matrix matrix) {
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.columns; j++) {
			printf("%d ", matrix.pointer[i][j]);
		}
		printf("\n");
	}
}

void MatrixAllocation(Matrix* matrix, int rows, int columns) {
	matrix->rows = rows;
	matrix->columns = columns;

	matrix->pointer = (int**)malloc((rows + 1) * sizeof(int*));
	for (int i = 0; i < rows; i++) {
		matrix->pointer[i] = (int*)malloc(columns * sizeof(int));
	}
}

void MatrixFree(Matrix matrix) {

	for (int i = 0; i < matrix.rows; i++) {
		free(matrix.pointer[i]);
	}

	free(matrix.pointer);
}

void MatrixFillAscending(Matrix matrix) {
	int contador = 0;
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.columns; j++) {
			matrix.pointer[i][j] = ++contador;
		}
	}
}