#include <biblioteca_c.h>

#define MATRIX_SIZE 5

typedef struct Matrix {
	// matriz[ROWS][COLUMNS];
	float** pointer;
	int rows;
	int columns;
} Matrix;

// Helper Functions
void printMatriz(Matrix matrix);
void MatrixAllocation(Matrix* matrix, int rows, int columns);
void MatrixFillAscending(Matrix matrix);
void MatrixFree(Matrix matrix);

bool MatrixScan(Matrix matrix, int i, int j) {
	printMatriz(matrix);

	int negativosLinhai = 0, negativosColunaj = 0;

	for (int k = 0; k < matrix.columns; k++) {
		if (matrix.pointer[i][k] < 0) negativosLinhai++;
	}

	for (int k = 0; k < matrix.rows; k++) {
		if (matrix.pointer[k][j] < 0) negativosColunaj++;
	}

	return negativosLinhai == negativosColunaj ? true : false;
}

int main() {
	Matrix matrix;
	MatrixAllocation(&matrix, 3, 3);

	MatrixFillAscending(matrix);

	printf("%s\n", MatrixScan(matrix, 0, 0) ? "True! :)" : "False! :(");

	MatrixFree(matrix);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}

void printMatriz(Matrix matrix) {
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.columns; j++) {
			printf("%g%s", matrix.pointer[i][j], " ");
		}
		printf("\n");
	}
}

void MatrixAllocation(Matrix* matrix, int rows, int columns) {
	matrix->rows = rows;
	matrix->columns = columns;

	matrix->pointer = (float**)malloc((rows + 1) * sizeof(float*));
	for (int i = 0; i < rows; i++) {
		matrix->pointer[i] = (float*)malloc(columns * sizeof(float));
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
			contador++;
			matrix.pointer[i][j] = contador % 2 == 0 ? contador : -contador;
		}
	}
}