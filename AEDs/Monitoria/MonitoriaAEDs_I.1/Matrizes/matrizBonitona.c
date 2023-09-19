#include <biblioteca_c.h>
#include <matrix.h>

int main() {

	Matrix* matrix = NewMatrix(3, 3);

	MatrixFill(matrix);

	MatrixPrint(matrix);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}