#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

// Usar os generics pra fazer funções pra float também, ou outros tipos

typedef struct Matrix {
	// matriz[ROWS][COLUMNS];
	int** pointer;
	int	  rows;
	int	  columns;
} Matrix;

Matrix* NewMatrix(int rows, int columns) {
	Matrix* newMatrix = (Matrix*)malloc(sizeof(Matrix));

	newMatrix->rows	   = rows;
	newMatrix->columns = columns;

	newMatrix->pointer = (int**)malloc(rows * sizeof(int*));

	for (int i = 0; i < rows; i++) {
		newMatrix->pointer[i] = (int*)malloc(columns * sizeof(int));
	}

	return newMatrix;
}

// void MatrixAlloc(Matrix* matrix, int rows, int columns) { // Deprecated
// 	matrix->rows = rows;
// 	matrix->columns = columns;

// 	matrix->pointer = (int**)malloc(rows * sizeof(int*));
// 	for (int i = 0; i < rows; i++) {
// 		matrix->pointer[i] = (int*)malloc(columns * sizeof(int));
// 	}
// }

void MatrixPrint(Matrix* matrix) {
	int	  rows		= matrix->rows;
	int	  cols		= matrix->columns;
	int** matrixAux = matrix->pointer;

	int maxElementWidth = 0;
	// Find the maximum width of matrix elements
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int element		 = matrixAux[i][j];
			int elementWidth = 0;

			// Calculate the number of digits in the element
			while (element != 0) {
				element /= 10;
				elementWidth++;
			}

			if (elementWidth > maxElementWidth) {
				maxElementWidth = elementWidth;
			}
		}
	}

	printf("    ");
	for (int i = 0; i < matrix->columns; i++) {
		printf("%*d ", maxElementWidth, i);
	}
	printf("\n");

	// Print the matrix
	// printf("Matrix:\n");
	for (int i = 0; i < rows; i++) {
		printf("%d { ", i);
		for (int j = 0; j < cols; j++) {
			printf("%*d ", maxElementWidth, matrixAux[i][j]);
		}
		printf("}\n");
	}
}

void MatrixFree(Matrix* matrix) {

	for (int i = 0; i < matrix->rows; i++) {
		free(matrix->pointer[i]);
	}

	free(matrix->pointer);
	free(matrix);
}

void MatrixFill(Matrix* matrix) {
	int contador = 0;
	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->columns; j++) {
			matrix->pointer[i][j] = ++contador;
		}
	}
}

#endif