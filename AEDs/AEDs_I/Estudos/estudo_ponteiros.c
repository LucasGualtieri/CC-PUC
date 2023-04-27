#include <biblioteca_c.h>

int main() {
	SetConsoleOutputCP(65001);

	int x[5] = { 1, 2, 3, 4, 5 };
	int* xPtr = x;
	int** xPtrPtr = &xPtr;

	printf("xPtr[1]: %d\n", xPtr[1]);
	printf("*xPtr + 1: %d\n", *(xPtr + 1));
	printf("x[1]: %d\n", x[1]);
	// printf("*xPtrPtr[1]: %d\n", *(xPtrPtr[1])); Não é assimm que faz
	printf("*(*xPtrPtr + 1): %d\n", *(*xPtrPtr + 1));

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}