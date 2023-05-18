#ifndef MATRIX_H
#define MATRIX_H

#include "Cell.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
	int rows, columns;
	Cell *first, *last;
} Matrix;

// ----------------- Methods ----------------

void MatrixAlloc(int rows, int columns, Matrix* matrix) {
	matrix->rows = rows;
	matrix->columns = columns;

	matrix->first = NULL;
	matrix->last = NULL;
}

void MatrixInsert(int value, int row, int column);

// void MatrixInsertBeg(int value, Matrix* matrix) {

// 	Cell* newCell = NewCell(0, NULL, NULL, NULL, NULL);

// 	matrixNext
// 		matrix->first
// 		= newCell;

// 	if (matrix->first == NULL) {
// 	}
// }

void MatrixInsertEnd(int value, Matrix* matrix) {

	if (matrix->first == matrix->last) {
		MatrixInsertBeg(value, matrix);
		return;
	}

	for (int i = 0; true; i++) {
		Cell* search = matrix->first;

		for (int j = 0; j < i; j++, search = search->below) {
			if (search->below == NULL) {
				Cell* newBelow = newCell(value, search, NULL, NULL, NULL);
				search = newBelow;
				matrix->last = newBelow;
			}
		}

		for (int j = 0; j < matrix->columns; j++) {
			if (j < matrix->columns - 1 && search == matrix->last) {
				Cell* newRight = newCell(value, NULL, NULL, search, NULL);
				search->right = newRight;

				matrix->last = newRight;

				return;
			}
		}
	}

	// if (matrix.ultimo->right )

	// matrix.ultimo->prox->value = value;
	// ultimo->prox->ant = ultimo;
	// ultimo = ultimo->pro
}

Cell* MatrixGetCell(int row, int column, Matrix matrix) {
	// return MatrixGetCell(row, col, matrix).value;
}

int MatrixGet(int row, int column, Matrix matrix) {
	// return MatrixGetCell(row, col, matrix).value;
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

// void MatrixFill(Matrix matrix) {
// 	int aux;
// 	for (int i = 0; i < matrix.rows * matrix.columns; i++) {
// 		scanf("%d", aux);
// 		MatrixInsertEnd(matrix, aux); // To be created
// 	}
// }

#endif