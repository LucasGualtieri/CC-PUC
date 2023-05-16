#ifndef CELL_H
#define CELL_H

#include <stdlib.h>

typedef struct Cell {
	int value;
	Cell *above, *below, *left, *right;
} Cell;

// ----------------- Methods ----------------

// Cell* newCell(int value, Cell* above, Cell* below, Cell* left, Cell* right) {
// 	Cell* cell = (Cell*)malloc(sizeof(Cell));

// 	cell->value = value;

// 	cell->above = above;
// 	cell->below = below;
// 	cell->left = left;
// 	cell->right = right;
// }

Cell* newCell(int value) {
	Cell* cell = (Cell*)malloc(sizeof(Cell));

	cell->value = value;

	cell->above = NULL;
	cell->below = NULL;
	cell->left = NULL;
	cell->right = NULL;
}

#endif