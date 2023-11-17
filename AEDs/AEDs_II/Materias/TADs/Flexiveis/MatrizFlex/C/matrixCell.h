#include <stdlib.h>

#ifndef MATRIX_CELL_H
#define MATRIX_CELL_H

typedef struct MatrixCell {
	int value;
	struct MatrixCell *left, *right, *top, *bottom;
} MatrixCell;

MatrixCell* newMatrixCell(int value, MatrixCell* left, MatrixCell* top) {

	MatrixCell* cell = malloc(sizeof(MatrixCell));

	cell->value = value;
	cell->left = left;
	cell->right = NULL;
	cell->top = top;
	cell->bottom = NULL;

	return cell;
}

#endif