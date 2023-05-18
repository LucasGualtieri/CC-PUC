#ifndef CELL_H
#define CELL_H

#include <stdlib.h>

typedef struct Cell {
	int value;
	struct Cell *above, *below, *left, *right;
} Cell;

// ----------------- Methods ----------------

Cell* newCell(int value, Cell* above, Cell* below, Cell* left, Cell* right) {
	Cell* cell = (Cell*)malloc(sizeof(Cell));

	cell->value = value;

	cell->above = above;
	cell->below = below;
	cell->left = left;
	cell->right = right;

	return cell;
}

#endif