#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct IntegerArray {
	int	 size;
	int* buffer;
} IntegerArray;

bool contains(IntegerArray array, int element) {
	for (int i = 0; i < array.size; i++) {
		if (array.buffer[i] == element) return true;
	}
	return false;
}

int main() {
	IntegerArray array;
	array.size	 = 5;
	array.buffer = (int*)malloc(array.size * sizeof(int));

	for (int i = 0; i < 5; i++) {
		array.buffer[i] = i + 6;
	}

	int x = 8;

	printf("%s\n", contains(array, x) ? "Contém." : "Não contém.");

	free(array.buffer);

	return 0;
}