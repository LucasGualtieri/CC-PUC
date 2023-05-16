#include "Cell.h"
#include "Matrix.h"
#include <biblioteca_c.h>

int main() {

	Matrix matrix;

	readDimensions(&matrix);

	readMatrix(matrix);

	// printMatrix(matrix);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}