#include <biblioteca_c.h>

int main() {

	// int* arrayMallocado = (int*)malloc(4 * sizeof(int));
	int array[4] = {20, 10, 15, 100};

	printf("array: %p\n", &array);

	printf("array + 1: %p\n", array + 1);
	printf("array + 1: %d\n", *(array + 1));

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}