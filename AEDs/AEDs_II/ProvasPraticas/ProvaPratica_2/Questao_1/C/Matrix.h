#ifndef MATRIX_H
#define MATRIX_H

#include "Cell.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
	Cell *primeiro, *ultimo;
	int rows, columns;
} Matrix;

// ----------------- Methods ----------------

void MatrixAlloc(int rows, int columns, Matrix* matrix) {
	matrix->primeiro = newCell(0);
}

void MatrixInsert();
void MatrixInsertBeg();
void MatrixInsertEnd(Matrix matrix, int value) {

	// if (matrix.ultimo->right )

	// matrix.ultimo->prox->value = value;
	// ultimo->prox->ant = ultimo;
	// ultimo = ultimo->pro
}

int MatrixGet() {
	int value;
	return value;
}

// ------------ Helper Functions ------------

// void printMatrix(Matrix matrix) {
// 	for (int i = 0; i < matrix.rows; i++) {
// 		for (int j = 0; j < matrix.columns; j++) {
// 			printf("%d ", matrix.pointer[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

void MatrixFill(Matrix matrix) {
	int aux;
	for (int i = 0; i < matrix.rows * matrix.columns; i++) {
		scanf("%d", aux);
		// inserirFim(matrix, aux);
	}
}

#endif