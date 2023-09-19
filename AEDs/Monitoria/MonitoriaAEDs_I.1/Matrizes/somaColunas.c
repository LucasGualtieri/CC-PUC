#include <biblioteca_c.h>
#include <matrix.h>

bool method(Matrix* matrix) {
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < matrix->rows; i++) {
		sum1 += matrix->pointer[i][0];
	}

	for (int i = 0; i < matrix->rows; i++) {
		sum2 += matrix->pointer[i][matrix->columns - 1];
	}

	return sum1 == sum2;
}

int main() {

	Matrix* matrix = NewMatrix(10, 10);

	MatrixFill(matrix);

	MatrixPrint(matrix);

	printf("\n%s\n", method(matrix) ? "True" : "False");

	MatrixFree(matrix);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}